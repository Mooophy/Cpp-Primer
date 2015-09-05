/***************************************************************************
 *  @file       vec.h
 *  @author     Alan.W
 *  @date       02  FEB 2014
 *  @remark
 ***************************************************************************/

#ifndef VEC_H
#define VEC_H

#include <memory>

/**
 *  @brief a vector like class
 */
template<typename T>
class Vec
{
public:
    Vec():element(nullptr), first_free(nullptr), cap(nullptr){ }
    Vec(std::initializer_list<T> l);
    Vec(const Vec& v);

    Vec& operator =(const Vec& rhs);

    ~Vec();

    // memmbers
    void push_back(const T& t);

    std::size_t size() const    { return first_free - element; }
    std::size_t capacity()const { return cap - element; }

    T* begin() const { return element;      }
    T* end()   const { return first_free;   }

    void reserve(std::size_t n);

    void resize(std::size_t n);
    void resize(std::size_t n, const T& t);

private:
    // data members
    T* element;
    T* first_free;
    T* cap;

    std::allocator<T> alloc;

    // utillities
    void reallocate();
    void chk_n_alloc()  { if(size()==capacity()) reallocate(); }
    void free();

    void wy_alloc_n_move(std::size_t n);

    std::pair<T*, T*> alloc_n_copy(T* b, T* e);
};


// copy constructor
template<typename T>
Vec<T>::Vec(const Vec &v)
{
    /**
     * @brief newData is a pair of pointers pointing to newly allocated and copied
     *        from range : [b, e)
     */
    std::pair<T*, T*> newData = alloc_n_copy(v.begin(), v.end());

    element = newData.first;
    first_free = cap = newData.second;
}


// constructor that takes initializer_list<T>
template<typename T>
Vec<T>::Vec(std::initializer_list<T> l)
{
    // allocate memory as large as l.size()
    T* const newData = alloc.allocate(l.size());

    // copy elements from l to the address allocated
    T* p = newData;
    for(const auto &t : l)
        alloc.construct(p++, t);

    // build data structure
    element = newData;
    first_free = cap = element + l.size();
}


// operator =
template<typename T>
Vec<T>& Vec<T>::operator =(const Vec& rhs)
{
    // allocate and copy first to protect against self_assignment
    std::pair<T*, T*> newData = alloc_n_copy(rhs.begin(), rhs.end());

    // destroy and deallocate
    free();

    // update data structure
    element = newData.first;
    first_free = cap = newData.second;

    return *this;
}


// destructor
template<typename T>
Vec<T>::~Vec()
{
    free();
}



/**
 * @brief   allocate new memeory if nessary and push back the new T
 * @param t new T
 */
template<typename T>
void Vec<T>::push_back(const T &t)
{
    chk_n_alloc();
    alloc.construct(first_free++, t);
}



/**
 * @brief   preallocate enough memory for specified number of elements
 * @param n number of elements required
 */
template<typename T>
void Vec<T>::reserve(std::size_t n)
{
    // if n too small, just return without doing anything
    if(n <= capacity()) return;

    // allocate new memory and move data from old address to the new one
    wy_alloc_n_move(n);
}


/**
 *  @brief  Resizes to the specified number of elements.
 *  @param  n  Number of elements the %vector should contain.
 *
 *  This function will resize it to the specified
 *  number of elements.  If the number is smaller than the
 *  current size it is truncated, otherwise
 *  default constructed elements are appended.
 */
template<typename T>
void Vec<T>::resize(std::size_t n)
{
    resize(n, T());
}



/**
 *  @brief  Resizes it to the specified number of elements.
 *  @param  __new_size  Number of elements it should contain.
 *  @param  __x  Data with which new elements should be populated.
 *
 *  This function will resize it to the specified
 *  number of elements.  If the number is smaller than the
 *  current size the it is truncated, otherwise
 *  the it is extended and new elements are populated with
 *  given data.
 */
template<typename T>
void Vec<T>::resize(std::size_t n, const T &t)
{
    if(n < size())
    {
        // destroy the range [element+n, first_free) using destructor
        for(auto p = element + n; p != first_free;   )
            alloc.destroy(p++);
        // update first_free to point to the new address
        first_free = element + n;
    }
    else if(n > size())
    {
        for (auto i = size(); i != n; ++i)
            push_back(t);
    }
}


/**
 * @brief   allocate new space for the given range and copy them into it
 * @param b
 * @param e
 * @return  a pair of pointers pointing to [first element , one past the last) in the new space
 */
template<typename T>
std::pair<T*, T*>
Vec<T>::alloc_n_copy(T *b, T *e)
{
    // calculate the size needed and allocate space accordingly
    T* data = alloc.allocate(e-b);
    return { data, std::uninitialized_copy(b, e, data) };
    //            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    // which copies the range[first, last) to the space to which
    // the starting address data is pointing.
    // This function returns a pointer to one past the last element
}


/**
 * @brief   destroy the elements and deallocate the space previously allocated.
 */
template<typename T>
void Vec<T>::free()
{
    // if not nullptr
    if(element)
    {
        // destroy it in reverse order.
        for(auto p = first_free; p != element;    )
            alloc.destroy(--p);

        alloc.deallocate(element, capacity());
    }
}


/**
 * @brief   allocate memory for spicified number of elements
 * @param n
 * @note    it's user's responsibility to ensure that @param n is greater than
 *          the current capacity.
 */
template<typename T>
void Vec<T>::wy_alloc_n_move(std::size_t n)
{
    // allocate as required.
    std::size_t newCapacity = n;
    T* newData = alloc.allocate(newCapacity);

    // move the data from old place to the new one
    T* dest = newData;
    T* old  = element;
    for(std::size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*old++));

    free();

    // update data structure
    element     =   newData;
    first_free  =   dest;
    cap         =   element + newCapacity;
}


/**
 * @brief   Double the capacity and using std::move move the original data to the newly
 *          allocated memory
 */
template<typename T>
void Vec<T>::reallocate()
{
    // calculate the new capacity required
    std::size_t newCapacity = size() ? 2 * size() : 1;

    // allocate and move old data to the new space
    wy_alloc_n_move(newCapacity);
}



#endif // VEC_H
