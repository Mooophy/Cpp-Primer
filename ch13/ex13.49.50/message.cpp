/***************************************************************************
 *  @file       message.cpp
 *  @author     Alan.W
 *  @date       04  JAN 2014
 *  @remark
 ***************************************************************************/


#include "message.h"
#include "folder.h"

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::addFld(Folder *f)
{
    folders.insert(f);
}

void Message::remFld(Folder *f)
{
    folders.erase(f);
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);    //use std::set move assignment
    //!       ^^^^^^^^^^~~~~~~~~~~^~    make it a rvalue reference.

    //! make folders pointing to the old message to point to 'this' one.
    for(const auto &f : folders){
        f->remMsg(m);
        f->addMsg(this);
    }

    //! ensure that destroying m is harmless.
    m->folders.clear();
}

void Message::add_to_Folders(const Message &m)
{
    for(auto &f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for(auto &f : folders)
        f->remMsg(this);
}

//! copy constructor
Message::Message(const Message &m):
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

//! move constructor -- 08.Jan.2014
Message::Message(Message&& m):
    contents(std::move(m.contents))
{
    move_Folders(&m);
}

//! destructor
Message::~Message()
{
    remove_from_Folders();
}

//! operator =
Message&
Message::operator =(const Message& rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);

    return *this;
}

//! move assignment -- 08.Jan.2014
Message &
Message::operator =(Message &&rhs)
{
    if(this != &rhs){
        remove_from_Folders();
        contents = std::move(rhs.contents);
        //!        ^^^^^^^^^^~~~~~~~~~~~~^~ move assignment

        //! reset the Folder to point to this message
        move_Folders(&rhs);
    }

    return *this;
}


void swap(Message &lhs, Message &rhs)
{
    using std::swap; // not strictly needed in this case, but good habit
    // remove pointers to each Message from their (original) respective Folders
    for (auto f: lhs.folders)
        f->remMsg(&lhs);
    for (auto f: rhs.folders)
        f->remMsg(&rhs);
    // swap the contents and Folder pointer sets
    swap(lhs.folders, rhs.folders);     // uses swap(set&, set&)
    swap(lhs.contents, rhs.contents);   // swap(string&, string&)
    // add pointers to each Message to their (new) respective Folders
    for (auto f: lhs.folders)
        f->addMsg(&lhs);
    for (auto f: rhs.folders)
        f->addMsg(&rhs);
}
