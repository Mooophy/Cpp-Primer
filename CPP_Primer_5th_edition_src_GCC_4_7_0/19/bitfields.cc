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
 * reproduced. Any commercial use of this code requires the explicit written
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
#include <iostream>
using std::cout; using std::endl;

typedef unsigned int Bit;

class File {
    Bit mode: 2;       // mode has 2 bits
    Bit modified: 1;   // modified has 1 bit
    Bit prot_owner: 3; // prot_owner has 3 bits
    Bit prot_group: 3; // prot_group has 3 bits
    Bit prot_world: 3; // prot_world has 3 bits
    // operations and data members of File
public:
	// file modes specified as octal literals; see XREF(intLiterals)
	enum modes { READ = 01, WRITE = 02, EXECUTE = 03 };
	File &open(modes);
	void close();
	void write();
	bool isRead() const;
	void setWrite();
	void execute();
	bool isExecute() const;
};

void File::write()
{
    modified = 1;
    // . . .
}

void File::close()
{
    if (modified)
        // . . . save contents
	;
}

inline bool File::isRead() const { return mode & READ; }
inline void File::setWrite() { mode |= WRITE; }


File &File::open(File::modes m)
{
	mode |= READ;    // set the READ bit by default
	// other processing
	if (m & WRITE) // if opening READ and WRITE 
	// processing to open the file in read/write mode
	cout << "myFile.mode READ is set" << endl;
	return *this;
}

int main()
{
	File myFile;
	
	myFile.open(File::READ);
	if (myFile.isRead()) 
		cout << "reading" << endl;
	
	return 0;
}

