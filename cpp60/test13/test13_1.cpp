/******************
 * C++实例指针(this)
 * 
 * 参数与成员变量重名
 * ***************/
// 成员函数（包括构造函数）的参数与成员变量重名时，如果不特别指定，则使用的是参数。

#include <iostream>
#include <string>

using namespace std;

class ca
{
    string id;

public:
    ca(string id)
    {
        this->id = id;
    }
    void setID(string id)
    {
        this->id = id;
    }
    void print()
    {
        cout << "id:" << id << endl;
    }
};

int main()
{
    ca a("abc");
    a.print();

    a.setID("def");
    a.print();

    return 0;
}
