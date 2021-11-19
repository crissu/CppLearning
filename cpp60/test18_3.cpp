/******************
 * C++ const和mutable的使用
 * 
 * mutable与const为敌
 * ***************/
// 用mutable修饰成员变量，可以使该成员变量即使在const成员函数中也能被修改。

#include <iostream>

using namespace std;

class classA
{
    int x;
    mutable string y;

public:
    void get(int &i, string &s) const
    {
        int k;
        k = 10; //非成员变量可以修改
        //x = k;     //成员变量不能修改
        y = "小雅"; //mutable变量可以修改
        i = x, s = y;
    }
    void set(int i, string s)
    {
        x = i;
        y = s;
    }
};
int main()
{
    classA ca;
    ca.set(100, "C语言中文网");
    int i;
    string s;
    ca.get(i, s);
    cout << s << "--" << i << endl;
    return 0;
}
