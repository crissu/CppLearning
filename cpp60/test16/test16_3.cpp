/******************
 * C++new和delete的使用
 * 
 * 用new产生类的实例
 * ***************/
// 前面已经用了很多了。

#include <iostream>

using namespace std;

class classA
{
    int x;

public:
    classA(int x)
    {
        this->x = x;
    }
    int getX()
    {
        return x;
    }
};

int main()
{
    classA *p = new classA(200); //调用构造函数
    if (!p)
    {
        cout << "内存分配出错！！！" << endl;
        return 1;
    }
    cout << "x = " << p->getX() << endl;
    delete p; // 调用析构函数

    return 0;
}
