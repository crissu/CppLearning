/******************
 * C++虚函数和纯虚函数
 * 
 * 类型转换又出了问题
 * ***************/

#include <iostream>
#include <string>

using namespace std;

class CBase
{
public:
    void show()
    {
        cout << "CBase" << endl;
    }
};

class CDerive : public CBase
{
public:
    void show()
    {
        cout << "CDerive" << endl;
    }
};

int main()
{
    CDerive d;
    CBase &c = d; // 赋值时进行了类型转换，将CDerive类型转换成了CBase类型

    d.show();
    c.show();

    return 0;
}
