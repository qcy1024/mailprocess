#ifndef __MESSAGE__H
#define __MESSAGE__H
#include <set>
#include <string>
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

#endif