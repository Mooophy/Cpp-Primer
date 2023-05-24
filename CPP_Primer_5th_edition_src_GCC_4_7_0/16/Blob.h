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

#ifndef BLOB_H
#define BLOB_H

#include <iterator>
#include <string>
#include <vector>
#include <initializer_list>
#include <cstddef>
#include <stdexcept>
#include <utility>
#include <memory>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

// forward declarations needed for friend declarations in Blob
template <typename> class BlobPtr;   
template <typename> class Blob; // needed for parameters in operator==
template <typename T> 
    bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
	// each instantiation of Blob grants access to the version of
	// BlobPtr and the equality operator instantiated with the same type
	friend class BlobPtr<T>;
	friend bool operator==<T>
	       (const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	// constructors
	Blob(); 
	Blob(std::initializer_list<T> il);
	template <typename It> Blob(It b, It e); 
	Blob(T*, std::size_t);

	// return BlobPtr to the first and one past the last elements
	BlobPtr<T> begin() { return BlobPtr<T>(*this); }
	BlobPtr<T> end() 
	    { auto ret = BlobPtr<T>(*this, data->size()); 
	      return ret; }

	// number of elements in the Blob
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	// add and remove elements
	void push_back(const T &t) {data->push_back(t);}
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();

	// element access
	T& front();
	T& back();
	T& at(size_type);
	const T& back() const;
	const T& front() const;
	const T& at(size_type) const;
	T& operator[](size_type i); 
	const T& operator[](size_type i) const;

	void swap(Blob &b) { data.swap(b.data); }
private:
	std::shared_ptr<std::vector<T>> data; 

	// throws msg if data[i] isn't valid
	void check(size_type i, const std::string &msg) const;
};

// constructors
template <typename T>
Blob<T>::Blob(T *p, std::size_t n): 
              data(std::make_shared<std::vector<T>>(p, p + n)) { }

template <typename T>
Blob<T>::Blob():
	          data(std::make_shared<std::vector<T>>()) { }

template <typename T>     // type parameter for the class
template <typename It>    // type parameter for the constructor
    Blob<T>::Blob(It b, It e):
              data(std::make_shared<std::vector<T>>(b, e)) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il): 
              data(std::make_shared<std::vector<T>>(il)) { }

// check member
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

// element access members
template <typename T>
T& Blob<T>::front()
{
	// if the vector is empty, check will throw
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
T& Blob<T>::back() 
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T> void Blob<T>::pop_back() 
{
	check(0, "pop_back on empty Blob"); 
	data->pop_back(); 
}

template <typename T>
const T& Blob<T>::front() const 
{
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
const T& Blob<T>::back() const 
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::at(size_type i) 
{
	// if i is too big, check will throw, preventing access to a nonexistent element
	check(i, "subscript out of range");
	return (*data)[i];  // (*data) is the vector to which this object points
}

template <typename T>
const T&
Blob<T>::at(size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	// if i is too big, check will throw, preventing access to a nonexistent element
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
const T& 
Blob<T>::operator[](size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

// operators
template <typename T>
std::ostream&
operator<<(std::ostream &os, const Blob<T> a)
{
	os << "< ";
	for (size_t i = 0; i < a.size(); ++i) 
		os << a[i] << " ";
	os << " >";
	return os;
}

template <typename T>
bool
operator==(const Blob<T> lhs, const Blob<T> rhs)
{
	if (rhs.size() != lhs.size())
		return false;
	for (size_t i = 0; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

// BlobPtr throws an exception on attempts to access a nonexistent element 
template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> class BlobPtr : public std::iterator<std::bidirectional_iterator_tag,T> {
	friend bool 
	operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0): 
	        wptr(a.data), curr(sz) { }

	T &operator[](std::size_t i)
	{ auto p = check(i, "subscript out of range"); 
	  return (*p)[i];  // (*p) is the vector to which this object points
	}

	const T &operator[](std::size_t i) const
	{ auto p = check(i, "subscript out of range"); 
	  return (*p)[i];  // (*p) is the vector to which this object points
	}
    
    T& operator*() const
	{ auto p = check(curr, "dereference past end"); 
	  return (*p)[curr];  // (*p) is the vector to which this object points
	}
    T* operator->() const
	{ // delegate the real work to the dereference operator
	 return & this->operator*(); 
	}

    // increment and decrement
    BlobPtr& operator++();       // prefix operators
    BlobPtr& operator--();

    BlobPtr operator++(int);     // postfix operators
    BlobPtr operator--(int);
    
private:
	// check returns a shared_ptr to the vector if the check succeeds
	std::shared_ptr<std::vector<T>> 
		check(std::size_t, const std::string&) const;

	// store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<T>> wptr;  
    std::size_t curr;      // current position within the array
};

// equality operators
template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.wptr.lock().get() == rhs.wptr.lock().get() && 
	       lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs == rhs);
}

// check member
template <typename T>
std::shared_ptr<std::vector<T>> 
BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();   // is the vector still around?
	if (!ret)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= ret->size()) 
		throw std::out_of_range(msg);
	return ret; // otherwise, return a shared_ptr to the vector
}

// member operators
// postfix: increment/decrement the object but return the unchanged value
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    // no check needed here; the call to prefix increment will do the check
    BlobPtr ret = *this;   // save the current value
    ++*this;     // advance one element; prefix ++ checks the increment
    return ret;  // return the saved state
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    // no check needed here; the call to prefix decrement will do the check
    BlobPtr ret = *this;  // save the current value
	--*this;     // move backward one element; prefix -- checks the decrement
    return ret;  // return the saved state
}

// prefix: return a reference to the incremented/decremented object
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	// if curr already points past the end of the container, can't increment it
	check(curr, "increment past end of BlobPtr");
    ++curr;       // advance the current state
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	// if curr is zero, decrementing it will yield an invalid subscript
    --curr;       // move the current state back one element
    check(-1, "decrement past begin of BlobPtr");
    return *this;
}
#endif
