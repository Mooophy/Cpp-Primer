/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code

Rewrite the `biggies` function to use function-object classes in place of lambdas

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <algorithm>
using std::sort; using std::stable_sort; using std::for_each;

class ShorterString {
public:
    bool operator()(string const& s1, string const& s2) const { return s1.size() < s2.size(); }
};

class BiggerEqual {
    size_t sz_;
public:
    BiggerEqual(size_t sz) : sz_(sz) { }
    bool operator()(string const& s) { return s.size() >= sz_; }
};

class Print {
public:
    void operator()(string const& s) { cout << s << " "; }
};

string make_plural(size_t ctr, string const& word, string const& ending)
{
    return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies( vector<string> &words, vector<string>::size_type sz ) {
    elimDups(words);
    stable_sort(words.begin(), words.end(), ShorterString());
    auto wc = find_if(words.begin(), words.end(), BiggerEqual(sz));
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), Print());
    cout << endl;
}

int main()
{
    vector<string> vec{ "fox", "jumps", "over", "quick", "red", "red", "slow", "the", "turtle" };
    biggies(vec, 4);
}
