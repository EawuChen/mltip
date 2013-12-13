#include<iostream>

using namespace std;

class Message
{
    friend class Folder;
public:
    explicit Message(const string &str = ""): content(str) { }
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

private:
    string content;
    set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();
};


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

void Message::add_to_Folders(Message &m)
{
    for (auto f : m.folders)
	f->addMsg(this);
}

Message::Message(const Message &m) :
    content(m.content), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
	f->remMsg(this);
}

Message::~Message()
{
    remove_from_Folders();
}

Message & Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    content = rhs.content;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}


void swap(Message &lhs, Message &rhs)
{
    for (auto f : lhs.folders)
	f->remMsg();
    for (auto f : rhs.folders)
	f->remMsg();
    swap(lhs.folders, rhs.folders);
    swap(lhs.content, rhs.content);

    for (auto f : lhs.folders)
	f->addMsg(lhs);
    for (auto f : rhs.folders)
	f->addMsg(rhs);
}


in main(void)
{
    nullptr
    return 0;
}
