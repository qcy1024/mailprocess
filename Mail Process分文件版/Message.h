#ifndef __MESSAGE__H
#define __MESSAGE__H
#include <set>
#include <string>
using namespace std;

class Folder;

//Ϊ�û��ṩsave��remove��������������Message����ָ��Folder��/��ָ��Folder��ɾ����
class Message
{
    friend class Folder;
private:
    string contents;
    set<Folder*> folders;

    //���ߺ������ڱ���Ϣ��folders�б��м���/ɾ�����ļ���ָ��f
    void addFolder(Folder* f);
    void remFolder(Folder* f);

    //���ߺ������ڱ���Ϣfolders�б��е�����Folder��ɾ��ָ�����Ϣ��ָ��
    void remove_from_folders();
    void add_to_folders(const Message& m);
public:
    string getContents();
    set<Folder*> getFolders();

    //���캯���뿽������
    Message(const string& s = " ") :contents(s) {};
    Message(const Message& m);
    //�������������m2=m1��������Ĳ�������m2��contents�Լ�����ЩFolder�г��֣�ȫ������m1��contents�Լ�
    //m1���ֵ�Folder
    Message& operator =(Message& m);
    ~Message();

    //�ӿڣ�������Ϣ��������ļ���f
    void save(Folder& f);
    //�ӿڣ�������Ϣ�ڸ����ļ�����ɾ��
    void remove(Folder& f);
};

#endif