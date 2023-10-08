#include <iostream>
#include <string>
#include <set>
using namespace std;

class Folder;

class Message
{
    string contents;
    set<Folder*> folders;
    
public:
    Message(string c = "") :contents(c) {};
    Message(const Message& m);
    ~Message();
    
    //将本消息加入/移除文件夹f中
    void save(Folder& f);
    void remove(Folder& f);

    //删除所有文件夹中保存的指向本消息的指针
    void remove_from_folders();

    //将指向本消息的指针添加到所有m所在的文件夹中，用于拷贝控制
    void add_to_folders(Message& m);

    //访问私有成员
    set<Folder*> getFolders();
    string getContents();

};

class Folder
{
    set<Message*> messages;
public:
    Folder() {};
    void saveMsg(Message*);
    void remvMsg(Message*);
};

//Message的类方法
Message::Message(const Message& m)
{

}

Message::~Message()
{
    remove_from_folders();
}

void Message::save(Folder& f)
{
    this->folders.insert(&f);
    f.saveMsg(this);
}

void Message::remove(Folder& f)
{
    f.remvMsg(this);
    folders.erase(&f);
}

void Message::remove_from_folders()
{
    for (auto f : this->folders)
    {
        f->remvMsg(this);
    }
}

void Message::add_to_folders(Message& m)
{
    for (auto f : m.folders)
    {
        f->saveMsg(this);
    }
}

set<Folder*> Message::getFolders()
{
    return this->folders;
}

string Message::getContents()
{
    return this->contents;
}

//Folder的类方法
void Folder::saveMsg(Message* m)
{
    messages.insert(m);
}

void Folder::remvMsg(Message* m)
{
    messages.erase(m);
}

int main()
{
    Message m1("Hello,");
    Message m2("World");
    Message m3("!");
    Folder f1;
    Folder f2;
    m1.save(f1);
    m1.save(f2);
    m2.save(f2);
    m3.save(f2);

    return 0;
}

