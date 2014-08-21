/***************************************************************************
 *  @file       Block.h
 *  @author     Alan.W
 *  @date       12  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

//!
//! Exercise 14.8:
//! Define an output operator for the class you chose in exercise 7.40 from
//! § 7.5.1 (p. 291).
//!
//! Exercise 7.40:
//! Choose one of the following abstractions (or an abstraction of your own
//! choosing). Determine what data are needed in the class. Provide an appropriate
//! set of constructors. Explain your decisions.
//!
#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <vector>
#include <memory>

/**
 * @brief The Block class
 * roughly representing a bool logic block.
 * @note    1 block_id shoule be placed in inherited class.
 *          2 why didn't inline work?
 *
 */
class Block
{
    friend std::ostream& operator <<(std::ostream& os, const Block& b);
    friend int           operator  -(const Block &lhs, const Block &rhs);



public:
    typedef std::shared_ptr<bool>   Pointer;
    typedef std::size_t             Size;

    //! big 5
    Block() = delete;

    //! -- the only construct
    Block(Size sid
          , const std::vector<Pointer>& iv
          , const Pointer& op);

    //! copy constructor
    Block(const Block& b) = delete;

    //! operator =  assignment is not allowed
    Block& operator =(const Block& rhs) = delete;

    ~Block() {}

    bool isValid()      const;
    Size inputSize()    const;


private:
    const Size                      sq_id    = 0 ;
    const std::vector<Pointer>      input_v  = std::vector<Pointer>() ;
    const Pointer                   output   = Pointer() ;
};

//! operator <<
std::iostream&
operator <<(std::iostream& os, const Block& b);

//! return the difference between two sequence id
inline int
operator  -(const Block &lhs, const Block &rhs)
{
    return lhs.sq_id - rhs.sq_id;
}
#endif // BLOCK_H
