#include "Folder.h"

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