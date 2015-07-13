/***************************************************************************
*  @file       main.cpp
*  @author     Yue Wang
*  @date       04  Feb 2014
*                  Jul 2015
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/

#pragma once
#include <functional>
#include "delete.hpp"

namespace cp5
{
    template<typename T>
    class SharedPointer;

    template<typename T> 
    void swap(SharedPointer<T>& lhs, SharedPointer<T>& rhs)
    {
        using std::swap;
        swap(lhs.ptr, rhs.ptr);
        swap(lhs.ref_count, rhs.ref_count);
        swap(lhs.deleter, rhs.deleter);
    }

    template<typename T>
    class SharedPointer
    {
    public:
        //
        //  Default Ctor
        //
        SharedPointer()
            : ptr{ nullptr }, ref_count{ new std::size_t(1) }, deleter{ cp5::Delete{} }
        {}
        //
        //  Ctor that takes raw pointer
        //
        explicit SharedPointer(T* raw_ptr)
            : ptr{ raw_ptr }, ref_count{ new std::size_t(1) }, deleter{ cp5::Delete{} }
        {}
        //
        //  Copy Ctor
        //
        SharedPointer(SharedPointer const& other)
            : ptr{ other.ptr }, ref_count{ other.ref_count }, deleter{ other.deleter }
        {
            ++*ref_count;
        }
        //
        //  Move Ctor
        //
        SharedPointer(SharedPointer && other) noexcept
            : ptr{ other.ptr }, ref_count{ other.ref_count }, deleter{ std::move (other.deleter) }
        {
            other.ptr = nullptr;
            other.ref_count = nullptr;
        }
        //
        //  Copy assignment
        //
        SharedPointer& operator=(SharedPointer const& rhs)
        {
            //increment first to ensure safty when self-assignment
            ++*rhs.ref_count;   
            decrement_and_destroy();
            ptr = rhs.ptr, ref_count = rhs.ref_count, deleter = rhs.deleter;
            return *this;
        }
        //
        //  Move assignment
        //
        SharedPointer& operator=(SharedPointer && rhs) noexcept
        {
            cp5::swap(*this, rhs);
            rhs.decrement_and_destroy();
            return *this;
        }
        //
        //  Conversion operator
        //
        operator bool() const 
        { 
            return ptr ? true : false; 
        }
        //
        //  Dereference
        //
        T& operator* () const 
        { 
            return *ptr; 
        }
        //
        //  Arrow
        //
        T* operator->() const 
        { 
            return &this->operator *(); 
        }
        //
        //  Use count
        //
        std::size_t use_count() const 
        { 
            return *ref_count; 
        }
        //
        //  Get underlying pointer
        //
        T* get() const noexcept
        { 
            return ptr; 
        }
        //
        //  Check if the unique user
        //
        bool unique() const noexcept 
        { 
            return 1 == *refCount; 
        }
        //
        //  Swap
        //
        void swap(SharedPointer& rhs) 
        { 
            ::swap(*this, rhs); 
        }
        //
        // Free the object pointed to, if unique
        //
        void reset() noexcept 
        { 
            decrement_and_destroy(); 
        }
        //
        // Reset with the new raw pointer
        //
        void reset(T* pointer)
        {
            if (ptr != pointer)
            {
                decrement_n_destroy();
                ptr = pointer;
                ref_count = new std::size_t(1);
            }
        }
        //
        //  Reset with raw pointer and deleter
        //
        void reset(T *pointer, const std::function<void(T*)>& d)
        {
            reset(pointer);
            deleter = d;
        }
        //
        //  Dtor
        //
        ~SharedPointer()
        {
            decrement_and_destroy();
        }
    private:
        T* ptr;
        std::size_t* ref_count;
        std::function<void(T*)> deleter;

        void decrement_and_destroy()
        {
            if (ptr)
            {
                if (0 == --*ref_count)
                {
                    delete ref_count;
                    deleter(ptr);
                }
            }
            ref_count = nullptr;
            ptr = nullptr;
        }
    };
}//namespace
