/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       24  DEC 2013
 *  @remark
 ***************************************************************************/
//
// Exercise 12.17:
// Which of the following unique_ptr declarations are illegal or likely to
// result in subsequent program error? Explain what the problem is with each
// one.
//
// Exercise 12.18:
// Why doesn’t shared_ptr have a release member?
//  Because other shared_ptr that points the same object can still delete this
//  object.Thus, it's meaningless to provide this member
//  more detail can be found a thread on Stack Overflow:
//  http://stackoverflow.com/questions/1525764/how-to-release-pointer-from-boostshared-ptr


#include <iostream>
#include <vector>
#include <string>
#include <memory>


int main()
{
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef std::unique_ptr<int> IntP;


    /**
     * @brief  error: invalid conversion from 'int' to 'std::unique_ptr<int>::pointer { aka int* }' [-fpermissive]
     */
    //IntP p0(ix);


    /**
     * @brief The code below can compile, but will cause error at run time.
     *        The reason is that when the unique_ptr p1 is out of scope, delete will be called
     *        to free th object. But the object is not allocate using new.Thus, an error
     *        would be thrown by operating system.
     *  @badcode
     */
    //IntP p1(pi);


    /**
     * @brief This code can compile, but cause a dangling pointer at run time.
     *        The reason is that the unique_ptr will free the object the raw pointer
     *        is pointing to.
     * @badcode
     */
    //{ IntP p2(pi2); }


    /**
     * @brief   When the unique_ptr goes out of scope, it will call delete to free an
     *          obeject not allocated using new.
     * @badcode
     */
    //IntP p3(&ix);


    /**
     * @brief   Recommended.
     */
    //IntP p4(new int(2048));


    /**
     * @brief   error:   double free or corruption at run time
     *          two unique_ptr are pointing to the same object. Thus, when both are out of
     *          scope, Operating system will throw double free or corruption.
     * @badcode
     */
    //IntP p2(new int(555));
    //IntP p5(p2.get());

    return 0;
}
