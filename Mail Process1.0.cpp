#include <iostream>
#include <string>
#include <set>
using namespace std;

class Folder;

//为用户提供save、remove两个函数，将本Message存入指定Folder中/在指定Folder中删除。
class Message
{
    friend class Folder;
private:
    string contents;
    set<Folder*> folders;

    //工具函数：在本消息的folders列表中加入/删除新文件夹指针f
    void addFolder(Folder* f);
    void remFolder(Folder* f);

    //工具函数：在本消息folders列表中的所有Folder中删除指向此消息的指针
    void remove_from_folders();
    void add_to_folders(const Message& m);
public:
    string getContents();
    set<Folder*> getFolders();

    //构造函数与拷贝控制
    Message(const string& s = " ") :contents(s) {};
    Message(const Message& m);
    //拷贝复制运算符m2=m1完成这样的操作：把m2的contents以及在哪些Folder中出现，全都换成m1的contents以及
    //m1出现的Folder
    Message& operator =(Message& m);
    ~Message();

    //接口：将本消息存入给定文件夹f
    void save(Folder& f);
    //接口：将本消息在给定文件夹中删除
    void remove(Folder& f);
};

class Folder
{
    friend class Message;
private:
    set<Message*> messages;

    //工具函数：将给定消息的指针添加到本文件夹的messages中
    void addMsg(Message* m);
    //工具函数：将给定消息的指针在本文件夹中的messages中删除
    void remMsg(Message* m);

    void remove_from_messages();

public:
    set<Message*> getMessages();
    ~Folder();
};

string Message::getContents()
{
    return contents;
}
set<Folder*> Message::getFolders()
{
    return folders;
}

void Message::addFolder(Folder* f)
{
    this->folders.insert(f);
}
void Message::remFolder(Folder* f)
{
    this->folders.erase(f);
}

//接口：将本消息存入给定文件夹f
void Message::save(Folder& f)
{
    this->addFolder(&f);
    f.addMsg(this);
}
//接口：将本消息在给定文件夹中删除
void Message::remove(Folder& f)
{
    this->remFolder(&f);
    f.remMsg(this);
}

void Message::remove_from_folders()
{
    for (auto f : folders)
    {
        f->remMsg(this);
    }
}

void Message::add_to_folders(const Message& m)
{
    set<Folder*> Folders = m.folders;
    for (set<Folder*>::iterator iter = Folders.begin(); iter != Folders.end(); ++iter)
    {
        (*iter)->addMsg(this);
    }
}

Message::Message(const Message& m):contents(m.contents),folders(m.folders)
{
    this->add_to_folders(m);
}

Message& Message::operator =(Message& m)
{
    remove_from_folders();
    this->folders = m.folders;
    this->contents = m.contents;
    add_to_folders(m);

    return *this;
}

Message::~Message()
{
    remove_from_folders();
}


/*Folder的成员函数*/

//工具函数：将给定消息的指针添加到本文件夹的messages中
void Folder::addMsg(Message* m)
{
    messages.insert(m);
}
//工具函数：将给定消息的指针在本文件夹中的messages中删除
void Folder::remMsg(Message* m)
{
    messages.erase(m);
}

set<Message*> Folder::getMessages()
{
    return messages;
}

void Folder::remove_from_messages()
{
    for (auto m : messages)
        m->remFolder(this);
}

Folder::~Folder()
{
    remove_from_messages();
}

void test()
{
    Message m1("Hello,"), m2("World"), m3("!"), m5("sb");
    Folder f1, f2;
    m1.save(f1); m1.save(f2);
    m3.save(f2);
    m2.save(f2);
    m5.save(f2);
    Message m4(m1);
    //m1 = m5;
    m2 = m1;
    for (auto m : f1.getMessages()) {
        cout << m->getContents() << " ";
    }
    cout << endl;
    for (auto m : f2.getMessages()) {
        cout << m->getContents() << " ";
    }
    cout << endl;
}

int main()
{
    test();

    system("pause");
    return 0;
}

