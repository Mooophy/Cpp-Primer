/***************************************************************************
*  @file       main.cpp
*  @author     Yue Wang
*  @date       04  Feb 2014
*                  Jul 2015
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/

#pragma once

namespace cp5
{
    class Delete
    {
    public:
        template<typename T>
        void operator() (T* p) const
        {
            delete p;
        }
    };
}
