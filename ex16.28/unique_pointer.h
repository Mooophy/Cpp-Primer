#ifndef UNIQUE_POINTER_H
#define UNIQUE_POINTER_H

#include <DebugDelete.h>

//! forward declarations for friendship

template<typename, typename> class unique_pointer;
template<typename T,typename D> void
                swap(unique_pointer<T,D>& lhs, unique_pointer<T,D>& rhs);

/**
 *  @brief  std::unique_ptr like class template.
 */
template <typename T, typename D = DebugDelete>
class unique_pointer
{
    friend void swap<T,D>(unique_pointer<T,D>& lhs, unique_pointer<T,D>& rhs);

public:
    //! preventing copy and assignment
    unique_pointer(const unique_pointer&) = delete;
    unique_pointer& operator = (const unique_pointer&) = delete;

    //! default constructor and one taking T*
    unique_pointer() = default;
    explicit unique_pointer(T* up): ptr(up) { }

    //! move constructor
    unique_pointer(unique_pointer&& up) noexcept
        : ptr(up.ptr)   { up.ptr = nullptr; }

    //! move assignment
    unique_pointer& operator =(unique_pointer&& rhs) noexcept;

    //! std::nullptr_t assignment
    unique_pointer& operator =(std::nullptr_t n) noexcept;



    //! operator overloaded :  *  ->  bool
    T& operator  *() const   { return *ptr; }
    T* operator ->() const   { return & this->operator *(); }
     operator bool() const   { return ptr ? true : false;   }

    //! return the underlying pointer
    T* get() const noexcept { return ptr;}

    //! swap member using swap friend
    void swap(unique_pointer<T, D> &rhs)  {::swap(*this, rhs);}

    //! free and make it point to nullptr or to p's pointee.
    void reset()     noexcept { deleter(ptr); ptr = nullptr; }
    void reset(T* p) noexcept { deleter(ptr); ptr = p;       }

    //! return ptr and make ptr point to nullptr.
    T* release();


    ~unique_pointer()
    {
        deleter(ptr);
    }
private:
    T* ptr = nullptr;
    D  deleter = D();
};


//! swap
template<typename T, typename D>
inline void
swap(unique_pointer<T,D>& lhs, unique_pointer<T,D>& rhs)
{
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.deleter, rhs.deleter);
}

//! move assignment
template<typename T, typename D>
inline unique_pointer<T,D>&
unique_pointer<T,D>::operator =(unique_pointer&& rhs) noexcept
{
    //! prevent self-assignment
    if(this->ptr != rhs.ptr)
    {
        deleter(ptr);
        ptr = nullptr;
        ::swap(*this, rhs);
    }
    return *this;
}


//! std::nullptr_t assignment
template<typename T, typename D>
inline unique_pointer<T,D>&
unique_pointer<T,D>::operator =(std::nullptr_t n) noexcept
{
    if(n == nullptr)
    {
        deleter(ptr);   ptr = nullptr;
    }
    return *this;
}

 //! relinquish contrul by returnning ptr and making ptr point to nullptr.
template<typename T, typename D>
inline T*
unique_pointer<T,D>::release()
{
    T* ret = ptr;
    ptr = nullptr;
    return ret;
}
#endif // UNIQUE_POINTER_H
