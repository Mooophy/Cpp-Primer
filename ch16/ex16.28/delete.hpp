/***************************************************************************
*  @file       delete.hpp
*  @author     Yue Wang
*  @date       04  Feb 2014
*                  Jul 2015
*                  Oct 2015
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/

#pragma once

namespace cp5
{
    struct Delete
    {
        template<typename T>
        auto operator() (T* p) const
        {
            delete p;
        }
    };
}