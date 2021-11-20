/******************
 * C++派生类中调用基类成员
 * 
 * 基类和派生类具有相同成员时
 * ***************/
#include <iostream>
#include <string>

using namespace std;

class CBase
{
    string id;
    string name;

public:
    CBase(string s1, string s2) : name(s1), id("base-" + s2) {}
    void show()
    {
        cout << "name:" << name << endl;
        cout << "id:" << id << endl;
    }
};

class CDerive : public CBase
{
    string id;
    int age;

public:
    CDerive(string s1, int a, string s2) : age(a), id("base-" + s2), CBase(s1, s2) {}

    void show()
    {
        cout << "id:" << id << endl;
        cout << "age:" << age << endl;

        CBase::show();
    }
};

int main()
{
    CDerive d("Crissu", 25, "0001");
    d.show();
    cout << "----------" << endl;

    d.CBase::show();
    cout << "----------" << endl;

    CBase b("sujiajie", "0002");
    b.show();

    return 0;
}
