/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       24  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 12.16:
//! Compilers don’t always give easy-to-understand error messages if we attempt
//! to copy or assign a unique_ptr. Write a program that contains these errors
//! to see how your compiler diagnoses them.
//!


#include <iostream>
#include <vector>
#include <string>
#include <memory>


int main()
{
    typedef std::vector<std::string>    T;
    std::shared_ptr<T> sp = std::make_shared<T>();


    /**
     * @brief    error: conversion from 'std::shared_ptr<std::vector<std::basic_string<char> > >'
     *           to non-scalar type 'std::unique_ptr<std::vector<std::basic_string<char> > >'
     *           requested
     */
    //std::unique_ptr<T> up = sp;


    /**
     * @brief   error:  no match for 'operator=' in 'up = sp'
     */
    //std::unique_ptr<T> up;
    //up = sp;


    /** @brief  no complaint
      */
    //sp = std::unique_ptr<T>();


    /**
     * @brief   error:  conversion from 'std::shared_ptr<std::vector<std::basic_string<char> > >'
     *                  to non-scalar type 'std::unique_ptr<std::vector<std::basic_string<char> > >'
     *                  requested
     */
    //std::unique_ptr<T> up = std::make_shared<T>(new int(42));


    /**
     * @brief   error:  use of deleted function 'std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::vector<std::basic_string<char> >; _Dp = std::default_delete<std::vector<std::basic_string<char> > >; std::unique_ptr<_Tp, _Dp> = std::unique_ptr<std::vector<std::basic_string<char> > >]'
     */
    //std::unique_ptr<T> up1, up2;
    //up1 = up2;

    return 0;
}


