#include "Message.h"
#include <set>
#include <string>
#include "Folder.h"
using namespace std;

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

Message::Message(const Message& m) :contents(m.contents), folders(m.folders)
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