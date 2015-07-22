#include "ex13_34_36_37.h"
#include <iostream>

void swap(Message &lhs, Message &rhs) 
{
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

// Message Implementation

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

void Message::add_to_Folders(const Message &m) 
{
    for (auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m) 
    : contents(m.contents), folders(m.folders) 
{
    add_to_Folders(m);
}

void Message::remove_from_Folders() 
{
    for (auto f : folders)
        f->remMsg(this);
    folders.clear();
}

Message::~Message() 
{ 
    remove_from_Folders(); 
}

Message &Message::operator=(const Message &rhs) 
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void Message::print_debug() 
{ 
    std::cout << contents << std::endl; 
}

// Folder Implementation

void swap(Folder &lhs, Folder &rhs) 
{
    using std::swap;
    for (auto m : lhs.msgs)
        m->remFldr(&lhs);

    for (auto m : rhs.msgs)
        m->remFldr(&rhs);

    swap(lhs.msgs, rhs.msgs);

    for (auto m : lhs.msgs)
        m->addFldr(&lhs);

    for (auto m : rhs.msgs)
        m->addFldr(&rhs);
}

void Folder::add_to_Message(const Folder &f) 
{
    for (auto m : f.msgs)
        m->addFldr(this);
}

Folder::Folder(const Folder &f) 
    : msgs(f.msgs) 
{ 
    add_to_Message(f); 
}

void Folder::remove_to_Message() 
{
    for (auto m : msgs)
        m->remFldr(this);
    msgs.clear();
}

Folder::~Folder() 
{ 
    remove_to_Message(); 
}

Folder &Folder::operator=(const Folder &rhs) 
{
    remove_to_Message();
    msgs = rhs.msgs;
    add_to_Message(rhs);
    return *this;
}

void Folder::print_debug() 
{
    for (auto m : msgs)
        std::cout << m->contents << " ";
    std::cout << std::endl;
}

int main() 
{ 
    return 0;
}
