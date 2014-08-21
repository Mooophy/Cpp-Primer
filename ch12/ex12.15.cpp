/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       23  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 12.15:
//! Rewrite the first exercise to use a lambda (§ 10.3.2, p. 388)
//! in place of the end_connection function.
//!


#include <iostream>
#include <vector>
#include <string>
#include <memory>

/**
 * @brief   The functions here are from textbook.
 *          Note that all the structs and functions must be defined before thay are called.
 *          Otherwise the compiler will complain that:
 *          error   :   undefined reference to `disconnecct(connection)'
 */
struct destination{};
struct connection{};

connection
connect(destination*);

void
disconnecct(connection conn);

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

    /** @brief  implement the shared_ptr using a lambda.
      */
    std::shared_ptr<connection> p_conn(&conn, [](connection *p_c)
    {
        disconnecct(*p_c);
    });
}

void disconnecct(connection conn)
{

}

