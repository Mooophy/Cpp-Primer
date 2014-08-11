//! @Alan
//!
//! Exercise 10.33:
//! Write a program that takes the names of an input file and two output files.
//! The input file should hold integers. Using an istream_iterator read the
//! input file. Using ostream_iterators, write the odd numbers into the first
//! output file. Each value should be followed by a space. Write the even numbers
//! into the second file. Each of these values should be placed on a separate line.
//  note : many algorithms can be used directly on iostream iterators.
//         This excerise can be seen as an example.
//!


#include <fstream>
#include <algorithm>
#include <iterator>


void
one2two(const std::string &Ifnm, const std::string &OoddFnm, const std::string &OevenFnm);
int main()
{
    one2two("test_int.txt","odd.txt","even.txt");
    return 0;
}


void
one2two(const std::string &Ifnm, const std::string &OoddFnm, const std::string &OevenFnm)
{
    //! build input file stream and its iterators.
    std::ifstream fin(Ifnm);
    std::istream_iterator<int> fin_iter(fin), eof;

    //! build output file streams and their iterators.
    std::ofstream fOddOutput(OoddFnm),   fEvenOutput(OevenFnm);
    std::ostream_iterator<int> fOddOutput_iter(fOddOutput, " "), fEvenOutput_iter(fEvenOutput, "\n");


    //! using for_each algorithm to do operation on every element via a lambda
    std::for_each(fin_iter, eof,    [&](const int i)
    {
        //! if odd  , output into the odd   file and incerment the iterator
        //! if even , output into the even  file and incerment the iterator
        i%2 ?   *fOddOutput_iter++ = i  : *fEvenOutput_iter++ = i;
    });
}
