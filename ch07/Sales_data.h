#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data{
	
	//old data.
	std::string bookNo;
	unsigned units_sold =0;
	double revenue = 0.0;
	
	//update define new function.
	std::string isbn() const{return bookNo;}
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
};

//update define not of Sales_data member function
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);




#endif