#include <iostream>
#include <string>
#include <set>
#include "Folder.h"
#include "Message.h"
using namespace std;

void test()
{
    Message m1("Hello,"), m2("World"), m3("!"), m5("haha");
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
    test();
    system("pause");
    return 0;
}

