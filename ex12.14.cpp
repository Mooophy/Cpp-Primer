/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       23  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 12.14:
//! Write your own version of a function that uses a shared_ptr to manage
//! a connection.
//!


#include <iostream>
#include <vector>
#include <string>
#include <memory>

struct destination{};
struct connection{};

connection
connect(destination*);

void
disconnecct(connection conn);

void
close(connection* conn);

void
wy_f(destination &d);

int main()
{
    return 0;
}


connection connect(destination *)
{
    connection conn;
    return  conn;
}


void wy_f(destination &d)
{
    connection conn = connect(&d);
    std::shared_ptr<connection> p_conn(&conn,close);
}


void close(connection *conn)
{
    //do sth.
}
