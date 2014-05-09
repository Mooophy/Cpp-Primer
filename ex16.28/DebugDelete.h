/***************************************************************************
 *  @file       DebugDelete.h
 *  @author     Alan.W
 *  @date       04  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <iostream>

/**
 * @brief The DebugDelete class is a deleter functor using delete
 */
class DebugDelete
{
public:
    DebugDelete(std::ostream& s = std::cerr) : os(s) { }
    template<typename T>
    void operator() (T* p) const
    {
        os << "deleting ptr" << std::endl;
        delete p;
    }

private:
    std::ostream& os;
};
#endif // DEBUGDELETE_H
