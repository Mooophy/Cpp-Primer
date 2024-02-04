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

#ifndef DEBUG_H
#define DEBUG_H
class Debug {
public:
	constexpr Debug(bool b = true): hw(b), io(b), other(b) { }
	constexpr Debug(bool h, bool i, bool o): 
	                                hw(h), io(i), other(o) { }
	constexpr bool any() { return hw || io || other; }
	constexpr bool hardware() { return hw || io; }
	constexpr bool app() { return other; }

	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { hw = b; }
private:
	bool hw;    // hardware errors other than IO errors
	bool io;    // IO errors
	bool other; // other errors
};

class HW_Subsystem {
public:
	HW_Subsystem(): debug(false) { }          // by default no debugging
	bool field_debug()   { return debug.any(); }
	bool default_debug() { return enable.any() && debug.any(); }
	void set_debug(bool b) { debug.set_hw(b); }  // turn on hardware debugging
private:
	Debug debug;
	constexpr static Debug enable{true, false, false};
};

class IO_Subsystem {
public:
	IO_Subsystem(): debug(false) { }          // by default no debugging
	bool field_debug()     { return debug.any(); }
	bool default_debug()   { return enable.any() && debug.any(); }
	void set_debug(bool b) { debug.set_io(b); }  // turn on IO debugging
private:
	Debug debug;
	constexpr static Debug enable{true, false, true};
};
#endif
