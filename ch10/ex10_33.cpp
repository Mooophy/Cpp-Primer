//
//  ex10_33.cpp
//  Exercise 10.33
//
//  Created by pezy on 12/13/14.
//
//  Write a program that takes the names of an input file and two output files.
//  The input file should hold integers. Using an istream_iterator read the input file.
//  Using ostream_iterators, write the odd numbers into the first output file.
//  Each value should be followed by a space.Write the even numbers into the second file.
//  Each of these values should be placed on a separate line.
//
//  Run: ./a.out "../data/input.txt" "../data/odd.txt" "../data/even.txt"

#include <fstream>
#include <iterator>
#include <algorithm>

int main(int argc, char **argv)
{
    if (argc != 4) return -1;

    std::ifstream ifs(argv[1]);
    std::ofstream ofs_odd(argv[2]), ofs_even(argv[3]);

    std::istream_iterator<int> in(ifs), in_eof;
    std::ostream_iterator<int> out_odd(ofs_odd, " "), out_even(ofs_even, "\n");

    std::for_each(in, in_eof, [&out_odd, &out_even](const int i){
        *(i & 0x1 ? out_odd : out_even)++ = i;
    });

    return 0;
}
