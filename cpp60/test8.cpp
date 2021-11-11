#include <iostream>
#include <string>
using namespace std;

/******************
 * C++基类与派生类的构造函数
 * ***************/

// 缺省构造函数的调用关系
// class CBase{
//     string name;
//     int age;
//     public:
//     CBase(){
//         cout<<"BASE"<<endl;
//     }
//     ~CBase(){
//         cout<<"~BASE"<<endl;
//     }
// };

// class CDerive:public CBase{
//     public:
//     CDerive(){
//         cout<<"DERIVE"<<endl;
//     }
//     ~CDerive(){
//         cout<<"~DERIVE"<<endl;
//     }
// };

// int main(){
//     CDerive d;

//     return 0;
// }

// // 有参数时的传递
// class CBase
// {
//     string name;

// public:
//     CBase(string s) : name(s)
//     {
//         cout << "BASE:" << name << endl;
//     }
//     ~CBase()
//     {
//         cout << "~BASE" << endl;
//     }
// };

// class CDerive : public CBase
// {
//     int age;

// public:
//     CDerive(string s, int i) : CBase(s), age(i)
//     {
//         cout << "DERIVE:" << age << endl;
//     }
//     ~CDerive()
//     {
//         cout << "~CDERIVE" << endl;
//     }
// };

// int main()
// {
//     CDerive d("crissu", 24);

//     return 0;
// }

// // 祖孙三代的参数传递
// class CBase
// {
//     string name;

// public:
//     CBase(string s) : name(s)
//     {
//         cout << "BASE:" << name << endl;
//     }
//     ~CBase()
//     {
//         cout << "~BASE" << endl;
//     }
// };

// class CDerive : public CBase
// {
//     int age;

// public:
//     CDerive(string s, int i) : CBase(s), age(i)
//     {
//         cout << "DERIVE:" << age << endl;
//     }
//     ~CDerive()
//     {
//         cout << "~CDERIVE" << endl;
//     }
// };

// class CSon : public CDerive
// {
//     string id;

// public:
//     CSon(string s, int a, string s2) : CDerive(s, a), id(s2)
//     {
//         cout << "SON:" << id << endl;
//     }
//     ~CSon()
//     {
//         cout << "~SON" << endl;
//     }
// };

// int main()
// {
//     CSon s("crissu", 24, "1234");

//     return 0;
// }


// 多重继承的参数传递
class CBase1
{
    string name;

public:
    CBase1(string s) : name(s)
    {
        cout << "BASE1:" << name << endl;
    }
    ~CBase1()
    {
        cout << "~BASE1" << endl;
    }
};

class CBase2
{
    int age;

public:
    CBase2(int i) : age(i)
    {
        cout << "BASE2:" << age << endl;
    }
    ~CBase2()
    {
        cout << "~BASE2" << endl;
    }
};

class CDerive : public CBase1, public CBase2 {
    string id;
public:
    CDerive(string s1, int a, string s2) : CBase1(s1), CBase2(a), id(s2) {
        cout << "DERIVE: " << id << endl;
    }
    ~CDerive() {
        cout << "~DERIVE" << endl;
    }
};

int main()
{
    CDerive d("crissu", 25, "1234");

    return 0;
}