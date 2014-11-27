/***************************************************************************
*  @file       main.cpp
*  @author     Queequeg
*  @date       26  Nov 2014
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/
//!
//! Exercise 8.13
//! Rewrite the phone number program from this section to read from a named 
//! file rather than from cin.

//!
//! Exercise 8.14
//! Why did we declare entry and nums as const auto &?
//! We don't expect to modify the original data.

#include<iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

#include<fstream>
using std::ifstream;
using std::ofstream;

#include<sstream>
using std::istringstream;
using std::ostringstream;

#include<string>
using std::string;

#include<vector>
using std::vector;

struct PersonInfo {
	string name;
	vector<string> phones;
};

bool read_record(istream& is, vector<PersonInfo>& people);
void format_record(ostream& os, const vector<PersonInfo>& people);

//! fake functions that make the program compile
bool valid(const string &num){ return true; }
string format(const string &num){ return num; }

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
	for (const auto &entry : people) 
	{
		// for each entry in people
		ostringstream formatted, badNums; // objects created on each loop
		for (const auto &nums : entry.phones) 
		{
			// for each number
			if (!valid(nums)) 
			{
				badNums << " " << nums; // string in badNums
			}
			else
				// "writes" to formatted's string
				formatted << " " << format(nums);
		}
		if (badNums.str().empty()) // there were no bad numbers
			os << entry.name << " " // print the name
			   << formatted.str() << endl; // and reformatted numbers
		else // otherwise, print the name and bad numbers
			cerr << "input error: " << entry.name
			     << " invalid number(s) " << badNums.str() << endl;
	}
}