/***************************************************************************
 *  @file       folder.h
 *  @author     Alan.W
 *  @date       04  JAN 2014
 *  @remark
 ***************************************************************************/
#ifndef FOLDER_H
#define FOLDER_H

#include <set>
#include <string>

class Message;

class Folder
{
    friend class Message;
    friend void swap(Message &lhs, Message &rhs);
    friend void swap(Folder& lhs, Folder& rhs);
public:
    //! default constructor
    explicit Folder(const std::string& s = ""):
        name(s),
        messages(std::set<Message*>())
    { }

    //! copy constructor
    Folder(const Folder& rhs);

    //! operator =
    Folder&
    operator = (const Folder& rhs);

    ~Folder();                  //destructor

private:

    void addMsg(Message* p_m);
    void remMsg(Message* p_m);

    //! data members
    std::string         name;
    std::set<Message*>  messages;
};

void swap(Folder& lhs, Folder& rhs);

#endif // FOLDER_H
