/***************************************************************************
 *  @file       shared_pointer.h
 *  @author     Alan.W
 *  @date       04  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note       06  Feb 2014    ctor taking std::shared_ptr&& added
 ***************************************************************************/
#ifndef SHARED_POINTER_H
#define SHARED_POINTER_H

#include "DebugDelete.h"
#include <functional>
#include <memory>

//! forward declarations needed for friendship

template<typename> class shared_pointer;
template<typename T> void swap(shared_pointer<T>& lhs, shared_pointer<T>& rhs);


/**
 *  @brief shared_ptr like template class
 *  @note   don't mix this one with std::shared_ptr.
 *          DebugDelete is the default deleter which can be replaced at run time
 */
template <typename T>
class shared_pointer
{
    friend void ::swap<T>(shared_pointer<T>& lhs, shared_pointer<T>& rhs);
    //!               ^^^ -- don't forget this.

public:

    //! default constructor
    shared_pointer() = default;

    //! constructor taking raw pointer.
    //! set the refCount as 1
    explicit shared_pointer(T* up, std::function<void(T*)> d = DebugDelete()) :
        ptr(up), refCount(new std::size_t(1)), deleter(d) { }

    //! ctor taking std::shared_ptr&& i.e. rvalue reference
    explicit shared_pointer(std::shared_ptr<T>&& sp,
                            std::function<void(T*)> d = DebugDelete());

    //! copy constructor.
    //! increment useCount for each Copy
    shared_pointer(const shared_pointer& sp):
        ptr(sp.ptr), refCount(sp.refCount), deleter(sp.deleter)
    { ++*refCount; }

    //! move constructor
    shared_pointer(shared_pointer&& sp) noexcept;

    //! copy assignment
    shared_pointer& operator =(const shared_pointer& rhs);

    //! move assignment
    shared_pointer& operator =(shared_pointer&& rhs) noexcept;


    //! conversion operator
    operator bool() const { return ptr ? true : false;}

    //! dereference *     arrow ->
    T& operator* () const { return *ptr; }
    T* operator->() const { return & this->operator *(); }

    //! return useCount
    std::size_t use_count() const { return *refCount; }

    //! get the underlying pointer
    T* get() const noexcept { return ptr; }

    //! check if the unique user
    bool unique() const noexcept { return *refCount == 1;}

    //! swap member
    void swap( shared_pointer& rhs) { ::swap(*this, rhs); }

    //! if unique user, free the object pointed to
    void reset() noexcept { decrement_n_destroy(); }

    //! make prt point where p pointing and create a new coount for it
    void reset(T* p);

    //! reset to point where p is pointing and change deleter to d.
    void reset(T *p, const std::function<void(T*)>& d)
    {   reset(p);   deleter = d;   }


    ~shared_pointer()
    {
        decrement_n_destroy();
    }
private:

    T* ptr = nullptr;
    std::size_t* refCount = new std::size_t(0);

    //! any functor lambda or function pointer that matched this
    //! signature can replace the default one at run time.
    std::function<void(T*)> deleter{DebugDelete()};
    //!                            ^~~~~~~~~~~~~~^
    //!                         here: = doesn't work, another way is initializing it in constructor.

    //! utilities
    void decrement_n_destroy();
};



/**
 *  @brief swap and big 5
 */
template <typename T>
inline void
swap(shared_pointer<T>& lhs, shared_pointer<T>& rhs)
{
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.refCount, rhs.refCount);
    swap(lhs.deleter, rhs.deleter);
}


/**
 *  @brief  ctor taking std::shared_ptr&& i.e. rvalue reference
 *  an interface between shared_pointer and std::shared_ptr.
 *  only rvalue AND unique ownership can use this ctor.
 */
template <typename T>
inline
shared_pointer<T>::shared_pointer(std::shared_ptr<T>&& sp,
                                  std::function<void(T*)> d)
{
    if(sp.unique())
        *this = shared_pointer(new T(*sp), d);
    else
        throw std::runtime_error
            ("only unique and rvalue reference can transfer ownership--@Alan\n");
}


//! move constructor
template<typename T>
inline
shared_pointer<T>::shared_pointer(shared_pointer&& sp) noexcept:
    ptr(sp.ptr), refCount(sp.refCount), deleter(std::move(sp.deleter))
{
    sp.ptr = nullptr;
    sp.refCount = nullptr;
}


//! copy assignment
template<typename T>
inline shared_pointer<T>&
shared_pointer<T>::operator =(const shared_pointer& rhs)
{
    //! increment rhs.refCount first to ensure safty when self-assignment
    ++*rhs.refCount;

    //! for lhs:
    decrement_n_destroy();

    //! copy datastructure from rhs to this.
    ptr = rhs.ptr;
    refCount = rhs.refCount;
    deleter  = rhs.deleter;

    return *this;
}


//! move assignment
template<typename T>
inline shared_pointer<T>&
shared_pointer<T>::operator =(shared_pointer&& rhs) noexcept
{
    //! for lhs
    decrement_n_destroy();

    //! swap two sides
    ::swap(*this, rhs);

    std::cout << "shared_pointer::move=\n";

    return *this;
}


//! make prt point where p pointing and create a new coount for it
template<typename T>
inline void
shared_pointer<T>::reset(T* p)
{
    if(ptr != p)
    {
        decrement_n_destroy();
        ptr = p;
        refCount = new std::size_t(1);
    }
}


/**
 *@brief operators: <<
 **/

template <typename T>
inline std::ostream&
operator <<(std::ostream& os, shared_pointer<T> p)
{
    os << p.get();
    return os;
}


//! utilities for decrement and delete using deleter.
template <typename T>
inline void
shared_pointer<T>::decrement_n_destroy()
{
    if(ptr)
    {
        if (--*refCount == 0)
        {
            delete refCount;
            deleter(ptr);
        }
        refCount = nullptr;
        ptr = nullptr;
    }
}

#endif // SHARED_POINTER_H
