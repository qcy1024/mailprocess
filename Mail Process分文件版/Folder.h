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

    //���ߺ�������������Ϣ��ָ����ӵ����ļ��е�messages��
    void addMsg(Message* m);
    //���ߺ�������������Ϣ��ָ���ڱ��ļ����е�messages��ɾ��
    void remMsg(Message* m);

    void remove_from_messages();

public:
    set<Message*> getMessages();
    ~Folder();
};

#endif