#include "ex13_49_Message.h"
#include <iostream>

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    std::cout << "Remove message from folders" << std::endl; // debug

    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    std::cout << "Remove message from folders" << std::endl; // debug

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    std::cout << "Message members swaped" << std::endl; // debug

    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    std::cout << "Added message to folders" << std::endl; // debug

    for (auto f : rhs.folders)
        f->addMsg(&rhs);
    std::cout << "Added message to folders" << std::endl; // debug
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message::~Message()
{
    remove_from_Folders();
}

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
    std::cout << "Added message to folders" << std::endl; // debug
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
    std::cout << "Remove message from folders" << std::endl; // debug
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    std::cout << "Message members assgined" << std::endl; // debug
    add_to_Folders(rhs);
    return *this;
}

void Message::print_debug()
{
    std::cout << contents << ": ";
    for (auto f : folders)
        std::cout << f->fldr() << " ";
    std::cout << std::endl;
}

void Message::move_Folders(Message *m)
{
	folders = std::move(m->folders);
	for (auto f : folders)
	{
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

Message::Message(Message &&m) : contents(std::move(m.contents))
{
    move_Folders(&m);
}

Message& Message::operator= (Message &&rhs)
{
    if (this != &rhs)
	{
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	std::cout << "Message members moved" << std::endl; // debug
	return *this;
}

// Folder Implementation

void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;
    for (auto m : lhs.msgs)
        m->remFldr(&lhs);
    std::cout << "clear folder" << std::endl; // debug

    for (auto m : rhs.msgs)
        m->remFldr(&rhs);
    std::cout << "clear folder" << std::endl; // debug

    swap(lhs.name, rhs.name);
    swap(lhs.msgs, rhs.msgs);
    std::cout << "Folder members swaped" << std::endl; // debug

    for (auto m : lhs.msgs)
        m->addFldr(&lhs);
    std::cout << "Added messages to folder" << std::endl; // debug

    for (auto m : rhs.msgs)
        m->addFldr(&rhs);
    std::cout << "Added messages to folder" << std::endl; // debug
}

void Folder::add_to_Message(const Folder &f)
{
    for (auto m : f.msgs)
        m->addFldr(this);
    std::cout << "Added messages to folder" << std::endl; // debug
}

Folder::Folder(const Folder &f) : name(f.name), msgs(f.msgs)
{
    add_to_Message(f);
}

void Folder::remove_from_Message()
{
    for (auto m : msgs)
        m->remFldr(this);
    std::cout << "clear folder" << std::endl; // debug
}

Folder::~Folder()
{
    remove_from_Message();
}

Folder& Folder::operator =(const Folder &rhs)
{
    remove_from_Message();
    name = rhs.name;
    msgs = rhs.msgs;
    std::cout << "Folder members assigned" << std::endl; // debug
    add_to_Message(rhs);
    return *this;
}

void Folder::print_debug()
{
    std::cout << name << ": ";
    for (auto m : msgs)
        std::cout << m->msg() << " ";
    std::cout << std::endl;
}

void Folder::move_Messages(Folder *f)
{
	msgs = std::move(f->msgs);
	for (auto m : msgs)
	{
		m->remFldr(f);
		m->addFldr(this);
	}
	f->msgs.clear();
}

Folder::Folder(Folder&& f) : name(std::move(f.name))
{
	move_Messages(&f);
}

Folder& Folder::operator=(Folder &&rhs)
{
    if (this != &rhs)
	{
		remove_from_Message();
		name = std::move(rhs.name);
		move_Messages(&rhs);
	}
	std::cout << "Message members moved" << std::endl; // debug
	return *this;
}
