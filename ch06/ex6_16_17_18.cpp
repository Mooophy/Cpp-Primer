//!@Alan
//!
//! Exercise 6.16: The following function, although legal, is less useful
//! than it might be. Identify and correct the limitation on this function:
//!     bool is_empty(string& s) { return s.empty(); }
//!
//  Since this function doesn't change the argument,"const" shoud be added
//  before string&s,otherwise this function is misleading and can't be used
//  with const string or in a const function.
//!
//! Exercise 6.17:
//! Write a function to determine whether a string contains any capital letters.
//! Write a function to change a string to all lowercase.
//! Do the parameters you used in these functions have the same type? If so,
//! why? If not, why not?
//!
//  Not the same.
//  For the first one "const" was used, since no change need to do for the argument.
//  For the second function,"const" can't be used,because the content of the agument
//  should be changed.
//!
//! Exercise 6.18:
//! Write declarations for each of the following functions.
//! When you write these declarations, use the name of the function to indicate what
//! the function does.
//! (a)
//! A function named compare that returns a bool and has two parameters that are
//! references to a class named matrix.
//  bool compare(const Matrix& _m1, const Matrix& _m2);
//!
//! (b)
//!  A function named change_val that returns a vector<int> iterator and takes two
//!  parameters: One is an int and the other is an iterator for a vector<int>.
//   See below.
//!



#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

//!
//! \brief      for Exercise 6.18.
//! \param _i   int
//! \param _vi  vector<int>::iterator
//! \return     vector<int>::iterator
//!
vector<int>::iterator change_val(int _i, vector<int>::iterator _vi);

//!
//! \brief      for Exercise 6.17
//!
bool is_anyCapital_usingPointer(const string& s);
bool is_anyCapital_usingIterator(const string& s);
void lowercaseAstring(string& s);

//!
//! \brief      for Exercise 6.16:
//!
bool is_empty(string& s);


int main()
{
    string str;

    cout<<"\nPlease enter:\n";
    while(cin>>str)
    {
        lowercaseAstring(str);
        cout<<"The lowercase=\n"
              <<str;
    }
    return 0;
}

bool is_anyCapital_usingIterator(const string& s)
{
    //!note: here must be   "string::const_iterator"
    //!      rather than    "string::iterator"
    for(string::const_iterator it = s.begin(); it != s.end(); ++it)
    {
        if(std::isupper(*it))
        {
            return true;
        }
    }
    return false;
}

bool is_anyCapital_usingPointer(const string& s)
{
    for(const char* p=&s[0];p != &s[s.size()]; p++)
    {
        if(std::isupper(*p))
        {
            return true;
        }
    }
    return false;
}


bool is_empty(string& s)
{
    return s.empty();
}


void lowercaseAstring(string& s)
{
    for(std::string::iterator it = s.begin(); it != s.end(); ++it)
    {
        *it = std::tolower(*it);
    }
}



