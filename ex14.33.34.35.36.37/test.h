/***************************************************************************
 *  @file       test.h
 *  @author     Alan.W
 *  @date       19  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/



#ifndef TEST_H
#define TEST_H

class test
{
public:
    test() = default;

    int operator()(bool c, int p1, int p2);
};

#endif // TEST_H
