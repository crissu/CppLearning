/******************
 * C++虚函数和纯虚函数
 * 
 * 纯虚函数
 * ***************/
// 虚继承的应用使程序设计发生了很大变化，也就是在设计阶段只定义基类，
// 而编程阶段通过继承来完成真正的功能。为了控制基类的成员函数在基类什么也不做，
// 引进了“纯虚函数”的概念，使之没有定义体，因而也就不能产生实例。包含“纯虚函数”的类，
// 因不能产生实例，所以称之为“抽象类”。

#include <iostream>
#include <string>

using namespace std;

// 抽象类
class CBase
{
public:
    virtual void show() = 0; // 纯虚函数
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

    // CBase cc;  // //抽象类不能实例化
    // cc.show();
    // cc.print();

    return 0;
}
