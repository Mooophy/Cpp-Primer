/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       04  JAN 2014
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.33:
//! Why is the parameter to the save and remove members of Message a Folder&?
//! Why didn’t we define that parameter as Folder? Or const Folder&?
//  Save and remove members perform operations not only on the Message objects,
//  but also on the arguments themselves.If the parameter is Folder, temporaty
//  obejcts will be created by copy constructor of Folder class. The operatopns
//  will be performed on the temporary obejcts rather than the arguments.
//  If a const is presected here, no operations are permited on the argument.
//!
//! Exercise 13.34:
//! Write the Message class as described in this section.
//!
//! Exercise 13.35:
//! What would happen if Message used the synthesized versions of the copy-control members?
//  Synthesized default constructor:
//  Does not matter. Essentially, the default constructor being used now is equivalent
//  to the synthesized version.
//
//  Synthesized destructor:
//  It will leave the pointers in the set of a folder objecct to the object being
//  destructed untouched. These pointers will become dangling.
//
//  Synthesized copy constructor:
//  It will not make the folders point back to the message object.
//
//  Synthesized copy assignment:
//  It will not remove the folders that originally point to it. Thus, after this
//  operation, all these pointers will point to wrong message.
//!
//! Exercise 13.36:
//! Design and implement the corresponding Folder class. That class should hold
//! a set that points to the Messages in that Folder.
//!
//! Exercise 13.37:
//! Add members to the Message class to insert or remove a given Folder* into
//! folders. These members are analogous to Folder’s addMsg and remMsg
//! operations.
//!
//! Exercise 13.38:
//! We did not use copy and swap to define the Message assignment operator.
//! Why do you suppose this is so?
//  The copy and swap is an elegant way when working with dynamicly allocated
//  memory. In the Message class ,noing is allocated dynamically. Thus using this
//  idiom makes no sense and will make it more complicated to implement due to the
//  pointers that point back.


#include "message.h"
#include "folder.h"
#include <iostream>

int main()
{
    Message m("sss");

    Folder f1("folder1");

    m.save(f1);

    Folder f2;
    swap(f1,f2);

    std::cout << "done!\n";


    return 0;
}






