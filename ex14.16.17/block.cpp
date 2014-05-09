/***************************************************************************
 *  @file       Block.cpp
 *  @author     Alan.W
 *  @date       12  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#include "block.h"
#include <iostream>

//! constructor
Block::Block(Size sid, const std::vector<Block::Pointer> &iv
             , const Block::Pointer &op) :
    sq_id(sid), input_v(iv), output(op)
{}



//! check if a valid block
bool Block::isValid() const
{
    return this->input_v.size()
            && this->output  && this->sq_id;
}

//! return how many input ports are used in this block
Block::Size
Block::inputSize() const
{
    return this->input_v.size();
}

//!
std::ostream &
operator <<(std::ostream &os, const Block &b)
{
    os << b.sq_id << " "
       << b.isValid() << " "
       << b.inputSize() << " ";

    return os;
}
