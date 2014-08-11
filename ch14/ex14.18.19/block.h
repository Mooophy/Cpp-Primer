/***************************************************************************
 *  @file       Block.h
 *  @author     Alan.W
 *  @date       12  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note       14  Jan 2014 : relation operators added
 ***************************************************************************/


#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <vector>
#include <memory>

/**
 * @brief The Block class
 * roughly representing a bool logic block.
 * @note    1 block_id shoule be placed in inherited class.
 *
 */
class Block
{
    friend std::ostream& operator <<(std::ostream& os, const Block& b);
    friend int           operator  -(const Block &lhs, const Block &rhs);
    friend bool operator ==(const Block& lhs, const Block& rhs);
    friend bool operator < (const Block& lhs, const Block& rhs);

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

//! operators
std::iostream&
operator <<(std::iostream& os, const Block& b);

//! return the difference between two sequence id
inline int
operator  -(const Block &lhs, const Block &rhs)
{
    return lhs.sq_id - rhs.sq_id;
}

inline bool
operator ==(const Block& lhs, const Block& rhs)
{
    return (lhs.sq_id == rhs.sq_id);
}

inline bool
operator !=(const Block& lhs, const Block& rhs)
{
    return !(lhs == rhs);
}

inline bool
operator < (const Block& lhs, const Block& rhs)
{
    return lhs.sq_id < rhs.sq_id;
}

inline bool
operator  >(const Block& lhs, const Block& rhs)
{
    if(lhs == rhs)  return false;
    else    return !(lhs < rhs);
}

inline bool
operator <=(const Block& lhs, const Block& rhs)
{
    return !(lhs > rhs);
}

inline bool
operator >=(const Block& lhs, const Block& rhs)
{
    return !(lhs < rhs);
}

#endif // BLOCK_H
