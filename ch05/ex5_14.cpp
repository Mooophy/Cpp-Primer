#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
	string word, max_word;
	vector<string> text;
	// get text
	while ( cin >> word )
		text.push_back(word);
	// process text
	unsigned word_cnt = 0, max_cnt = 0;
	vector<string>::size_type i = 0;
	while ( i < text.size() ) {
		while ( i+1 < text.size() && text[i] == text[i+1] ) {
			++word_cnt;
			++i;
		}
		if ( word_cnt > max_cnt ) {
			max_word = text[i];
			max_cnt = word_cnt;
		}
		word_cnt = 0; // reset
		++i;
	}
	// print result
	if ( max_cnt != 0 )
		cout << "\nThe word \"" << max_word << "\" occurred " << ++max_cnt << " times." << endl;
	else
		cout << "\nNo word was repeated." << endl;
	return 0;
}
