/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/ 

#include <cstddef>
#include <iostream>
#include <string>
using std::cout; using std::cin;
using std::endl;
using std::string;
using std::size_t;

#include <bitset>
using std::bitset;
int main() 
{
	bitset<32> bitvec(1U); // 32 bits; low-order bit is 1, 
	                       // remaining bits are 0
	bool is_set = bitvec.any();      // true, one bit is set
	bool is_not_set = bitvec.none(); // false, one bit is set
	bool all_set = bitvec.all();     // false, only one bit is set
	size_t onBits = bitvec.count();  // returns 1
	size_t sz = bitvec.size();       // returns 32
	
	bitvec.flip();     // reverses the value of all the bits in bitvec
	bitvec.reset();    // sets all the bits to 0
	bitvec.set();      // sets all the bits to 1
	
	cout << "bitvec: " << bitvec << endl;
	
	sz = bitvec.size();  // returns 32
	
	onBits = bitvec.count();  // returns 1, 
                              // i.e., the number of bits that are on
	
	// assign 1 to even numbered bits
	for (int index = 0; index != 32; index += 2)
		bitvec[index] = 1; 

	// equivalent loop using set operation
	for (int index = 0; index != 32; index += 2)
		bitvec.set(index); 
	
	// bitvec is unchanged
	auto b2 = ~bitvec;  // b2 is a copy of bitvec with every bit flipped

	// assign value of last bit in bitvec to the first bit in b2
	b2[0] = bitvec[bitvec.size() - 1]; 
	bitvec[0] = 0;          // turn off the bit at position 0
	bitvec[31] = bitvec[0]; // give last bit the same value as the first
	bitvec[0].flip();       // flip the value of the bit at position 0
	~bitvec[0];             // equivalent; flips the bit at position 0
	bool b = bitvec[0];     // convert the value of bitvec[0] to bool
	b2[0] = ~bitvec[0];     // first bit in b2 has the opposite value 
                            // of the first bit in bitvec
	
	unsigned i = 0;
	if (bitvec.test(i))
	     // bitvec[i] is on
	        ;
	
	//equivalent test using subscript
	if (bitvec[i])
	     // bitvec[i] is on
	        ;
	
	cout << "bitvec: positions turned on:\n\t";
	for (int index = 0; index != 32; ++index)
		if (bitvec[index])
	    	cout << index << " ";
	cout << endl;
	
	// equivalent; turn off first bit
	bitvec.flip(0);   // reverses the value of the first bit
	bitvec.set(bitvec.size() - 1);  // turns on the last bit
	bitvec.set(0, 0); // turns off the first bit
	bitvec.reset(i);  // turns off the ith bit 
	bitvec.test(0);   // returns false because the first bit is off
	bitvec[0] = 0;
	
	bitvec.flip(0);   // reverses value of first bit
	bitvec[0].flip(); // also reverses the first bit
	
	cout << "new inits" <<endl;
	// bits13 is smaller than the initializer; 
	// high-order bits from the initializer are discarded
	bitset<13> bits13(0xbeef);  // bits are 1111011101111 

	// bits20 is larger than the initializer; 
	// high-order bits in bits20 are set to zero
	bitset<20> bits20(0xbeef);  // bits are 00001011111011101111

	// on machines with 64-bit long long 0ULL is 64 bits of 0, 
	// so ~0ULL is 64 ones, so 0 ... 63 are one, and 64 ... 127 are zero
    // if long long has 32 bits, 0 ... 32 are one, 33 ... 127 are zero
	bitset<128> bits128(~0ULL); 
	cout << "bits13: " << bits13 << endl;
	cout << "bits20: " << bits20 << endl;
	cout << "bits128: " << bits128 << endl;
	cout << "bits20[0] " << bits20[0] << endl;
	cout << "bits20[19] " << bits20[19] << endl;
	
	// bitvec1 is smaller than the initializer
	bitset<32> bitvec1(0xffff);  // bits 0 ... 15 are set to 1; 
	                             // 16 ... 31 are 0
	
	// bitvec2 same size as initializer
	bitset<64> bitvec2(0xffff);  // bits 0 ... 15 are set to 1; 
	                             // 16 ... 63 are 0
	
	// assuming 64-bit long long, bits 0 to 63 initialized from 0xffff
	bitset<128> bitvec3(0xffff); // bits 32 through 127 are zero
	
	cout << "bitvec1: " << bitvec1 << endl;
	cout << "bitvec2: " << bitvec2 << endl;
	cout << "bitvec2[0] " << bitvec2[0] << endl;
	cout << "bitvec2[31] " << bitvec2[31] << endl;
	
	cout << "bitvec3: " << bitvec3 << endl;
	
	
	bitset<32> bitvec4("1100"); // bits 2 and 3 are 1, all others are 0
	
	cout << "strval: " << "1100" << endl;
	cout << "bitvec4: " << bitvec4 << endl;
	
	string str("1111111000000011001101");
	bitset<32> bitvec5(str, 5, 4); // four bits starting at str[5], 1100
	bitset<32> bitvec6(str, str.size()-4); // use last four characters 
	
	cout << "str: " << str << endl;
	cout << "bitvec5: " << bitvec5 << endl;
	
	cout << "str: " << str << endl;
	cout << "bitvec6: " << bitvec6 << endl;
	
	unsigned long ulong = bitvec3.to_ulong();
	cout << "ulong = " << ulong << endl;
	
	bitset<32> bitvec7 = bitvec1 & bitvec4;
	
	cout << "bitvec7: " << bitvec7 << endl;
	
	bitset<32> bitvec8 = bitvec1 | bitvec4;
	
	cout << "bitvec8: " << bitvec8 << endl;
	
	bitset<16> chk("111100110011001100000");
	cout << "chk: " << chk << endl;
	
	bitset<16> bits;
	cin >> bits;  // read up to 16 1 or 0 characters from cin
	cout << "bits: " << bits << endl; // print what we just read

	return 0;
}
