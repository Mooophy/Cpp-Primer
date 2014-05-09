/***************************************************************************
 *  @file       message.h
 *  @author     Alan.W
 *  @date       04  JAN 2014
 *  @remark     move operations added
 *              --08.Jan.2014
 ***************************************************************************/
#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>

class Folder;

class Message
{
    friend class Folder;
    friend void swap(Message&   lhs,    Message&    rhs);
    friend void swap(Folder&    lhs,    Folder&     rhs);
public:
    //! default constructor.
    explicit Message( const std::string &str = ""):
        contents(str){ }                // folders is implicitly initialized to empty set

    //! copy constructor
    Message(const Message& m);

    //! move constructor -- 08.Jan.2014
    Message(Message&& m);

    Message&
    operator =(const Message& rhs);

    //! move assignment -- 08.Jan.2014
    Message&
    operator =(Message&& rhs);

    //! destructor
    ~Message();

    //! public member functions
    void save(Folder& f);
    void remove(Folder& f);


private:

    //! for ex13.37
    void addFld(Folder *f);
    void remFld(Folder *f);

    //! for ex13.49 08.Jan.2014
    void move_Folders(Message* m);


    //! data members
    std::string contents;           // actual message text
    std::set<Folder*> folders;      // Folders that have this message

    //! utility functions
    void add_to_Folders(const Message& m);
    void remove_from_Folders();
};

void swap(Message &lhs, Message &rhs);

#endif // MESSAGE_H
