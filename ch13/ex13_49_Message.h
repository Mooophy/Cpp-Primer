#ifndef CP5_MESSAGE_H_
#define CP5_MESSAGE_H_

#include <string>
#include <set>

#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

class Folder;

class Message
{
    friend void swap(Message &, Message &);
    friend void swap(Folder &, Folder &);
    friend class Folder;
public:
    explicit Message(const std::string &str = "") : contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    Message(Message &&m); // need to update the Folders
    Message& operator=(Message&&); // need to update the Folders
    ~Message();

    void save(Folder&);
    void remove(Folder&);

    const std::string& msg() const { return contents; }
    void print_debug();

private:
    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
    
    void move_Folders(Message*); // define function to do the common work

private:
    std::string contents;
    std::set<Folder*> folders;
};

void swap(Message&, Message&);

class Folder {
    friend void swap(Message&, Message&);
    friend void swap(Folder &, Folder &);
    friend class Message;
public:
    explicit Folder(const std::string &str = "") :name(str) { }
    Folder(const Folder &);
    Folder& operator=(const Folder &);
    Folder(Folder &&f); // need to update the Messages
    Folder& operator=(Folder &&); // need to update the Messages
    ~Folder();

    const std::string& fldr() const { return name; }
    void print_debug();

private:
    std::string name;
    std::set<Message*> msgs;

    void add_to_Message(const Folder&);
    void remove_from_Message();

    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
    
    void move_Messages(Folder*); // define function to do the common work
};

void swap(Folder &, Folder &);

#endif
