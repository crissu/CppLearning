/******************
 * C++友元函数(friend)
 * 
 * 全局函数作友元
 * ***************/
// 要使用全局函数作友元函数，也就是说全局函数中要使用当前这个类的实例，
// 因此，全局函数的定义必须放在这个类的后面，否则，编译时这个类的实例就成了未定义的数据类型了。

#include <iostream>
#include <string>

using namespace std;

class ca
{
    string id;
    void setID(string s)
    {
        id = s;
    }

protected:
    string name;
    void setName(string s)
    {
        name = s;
    }

public:
    void print()
    {
        cout << id << " " << name << " " << endl;
    }
    friend void fun(ca &a); // 申明全局函数作友元，允许它访问私有保护成员
};

class derive : public ca // ca类的派生类
{
};

void fun(ca &a)
{                     //作友元的函数要定义在那个类的后面
    a.id = "987";     //这是ca类的私有成员
    a.setName("xyz"); //这是ca类的保护成员
}

int main()
{
    ca a;
    //a.fun(...);    //友元函数不是当前类的成员函数，所以这句编译出错
    fun(a);
    a.print();

    derive d;
    fun(d); //作参数时，类型转换为ca类
    d.print();

    return 0;
}
