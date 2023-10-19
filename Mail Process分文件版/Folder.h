#ifndef __FOLDER__H
#define __FOLDER__H
#include <set>
#include "Message.h"
using namespace std;
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

#endif