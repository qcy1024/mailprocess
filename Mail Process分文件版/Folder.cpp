#include "Folder.h"

/*Folder�ĳ�Ա����*/

//���ߺ�������������Ϣ��ָ����ӵ����ļ��е�messages��
void Folder::addMsg(Message* m)
{
    messages.insert(m);
}
//���ߺ�������������Ϣ��ָ���ڱ��ļ����е�messages��ɾ��
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