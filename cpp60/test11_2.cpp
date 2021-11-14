/******************
 * C++虚函数和纯虚函数
 * 
 * 虚函数
 * ***************/
// 注意：“虚继承”和“虚函数”是二个不同概念，
// “虚继承”针对基类的成员变量的二义性，而“虚函数”是针对成员函数的二义性。
// “虚继承”是将“virtual”加在派生类的定义处，“虚函数”是将“virtual”加在基类的成员函数的定义处。

#include <iostream>
#include <string>

using namespace std;

class CBase
{
public:
    virtual void show()
    {
        cout << "CBase Show" << endl;
    }
    virtual void print()
    {
        cout << "CBase Print" << endl;
    }
};

class CDerive : public CBase
{
public:
    void show()
    {
        cout << "CDerive show" << endl;
    }
};

int main()
{
    CDerive d;
    CBase &c = d;

    d.show();
    c.show();
    d.print();
    c.print();

    CBase cc;
    cc.show();
    cc.print();

    return 0;
}
