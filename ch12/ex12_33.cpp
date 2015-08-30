//
//  ex12_33.cpp
//  Exercise 12.33
//
//  Created by pezy on 1/1/15.
//
//  Rewrite the TextQuery and QueryResult classes to use a StrBlob
//  instead of a vector<string> to hold the input file.

#include "ex12_33.h"
#include <sstream>
#include <algorithm>

TextQuery::TextQuery(std::ifstream &ifs)
{
    StrBlob::size_type lineNo{ 0 };
    for (string line; std::getline(ifs, line); ++lineNo) {
        file.push_back(line);
        std::istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear()) {
            // avoid read a word followed by punctuation(such as: word, )
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            // use reference avoid count of shared_ptr add.
            auto &nos = result[word];
            if (!nos) nos.reset(new std::set<StrBlob::size_type>);
            nos->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(const string& str) const
{
    // use static just allocate once.
    static shared_ptr<std::set<StrBlob::size_type>> nodate(new std::set<StrBlob::size_type>);
    auto found = result.find(str);
    if (found == result.end()) return QueryResult(str, nodate, file);
    else return QueryResult(str, found->second, file);
}

std::ostream& print(std::ostream &out, const QueryResult& qr)
{
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
    for (auto it = qr.begin(); it != qr.end(); ++it) {
        ConstStrBlobPtr p(*qr.get_file(), *it);
        out << "\t(line " << *it + 1 << ") " << p.deref() << std::endl;
    }
    return out;
}
