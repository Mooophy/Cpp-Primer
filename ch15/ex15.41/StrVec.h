#ifndef STRVEC_H
#define STRVEC_H
#include <string>
#include <memory>
class StrVec
{
public:
	StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){}
	StrVec(const StrVec&);
	StrVec(std::initializer_list<std::string>);
	StrVec& operator=(const StrVec&);
	~StrVec();
	void push_back(const std::string&);
	size_t size() const{ return cap - elements; };
	size_t capacity() const{ return cap - elements; }
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
	void reserve(size_t size);
	size_t capacity();
	size_t size();	
	std::string at(size_t pos);
	void resize(size_t size);
	void resize(size_t size, std::string& T);
private:
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate();
	}
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate();
private:
	std::allocator<std::string> alloc;
	std::string* elements;
	std::string* first_free;
	std::string* cap;
};

#endif