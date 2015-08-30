/***************************************************************************
*  @file       main.cpp
*  @author     Queequeg
*  @date       26  Nov 2014
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/
//
// Exercise 17.21
// Rewrite your phone number program from 8.3.2 (p. 323) to use the 
// valid function defined in this section.

#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <sstream>
using std::istringstream;
using std::ostringstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <regex>
using std::regex;
using std::sregex_iterator;
using std::smatch;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const smatch& m);
bool read_record(istream& is, vector<PersonInfo>& people);
void format_record(ostream& os, const vector<PersonInfo>& people);

// fake function that makes the program compile
string format(const string &num) { return num; }

int main()
{
    vector<PersonInfo> people;

    string filename;
    cout << "Please input a record file name: ";
    cin >> filename;
    cout << endl;
    ifstream fin(filename);

    if (read_record(fin, people))
    {
        ofstream fout("data\\result.txt", ofstream::trunc);
        format_record(fout, people);
    }
    else
    {
        cout << "Fail to open file " << filename << endl;
    }

    return 0;
}

bool valid(const smatch& m)
{
    // if there is an open parenthesis before the area code
    if (m[1].matched)
        // the area code must be followed by a close parenthesis
        // and followed immediately by the rest of the number or a space
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    else
        // then there can't be a close after the area code
        // the delimiters between the other two components must match
        return !m[3].matched && m[4].str() == m[6].str();
}

bool read_record(istream& is, vector<PersonInfo>& people)
{
    if (is)
    {
        string line, word; // will hold a line and word from input, respectively
                           // read the input a line at a time until cin hits end-of-file (or another error)
        while (getline(is, line))
        {
            PersonInfo info; // create an object to hold this record's data
            istringstream record(line); // bind record to the line we just read
            record >> info.name; // read the name
            while (record >> word) // read the phone numbers
                info.phones.push_back(word); // and store them
            people.push_back(info); // append this record to people
        }
        return true;
    }
    else
        return false;
}

void format_record(ostream& os, const vector<PersonInfo>& people)
{
    string phone = "(\\()?(\\d{ 3 })(\\))?([-. ])?(\\d{ 3 })([-. ]?)(\\d{ 4 })";
    regex r(phone);
    smatch m;

    for (const auto &entry : people)
    {
        // for each entry in people
        ostringstream formatted, badNums; // objects created on each loop
        for (const auto &nums : entry.phones)
        {
            for (sregex_iterator it(nums.begin(), nums.end(), r), end_it; it != end_it; ++it)
            {
                // for each number
                // check whether the number's formatting is valid
                if (!valid(*it))
                    // string in badNums
                    badNums << " " << nums;
                else
                    // "writes" to formatted's string
                    formatted << " " << format(nums);
            }
        }

        if (badNums.str().empty()) // there were no bad numbers
            os << entry.name << " " // print the name
            << formatted.str() << endl; // and reformatted numbers
        else // otherwise, print the name and bad numbers
            cerr << "input error: " << entry.name
            << " invalid number(s) " << badNums.str() << endl;
    }
}
