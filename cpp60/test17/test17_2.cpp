/******************
 * C++静态类成员
 * 
 * 静态成员函数
 * ***************/
// 笔者多年从事Java程序设计，按Java的经验，静态成员函数一般在公共程序中用的比较多。
// 这样的程序与类自身关系不大，只是归类性质放在某个类中。还有一些与类转换或交换但不需要实例时使用的情况。

#include <iostream>
#include <string>

using namespace std;

class Integer
{
public:
    static int atoi(const char *s)
    {
        return ::atoi(s);
    }
    static float atof(const char *s)
    {
        return ::atof(s);
    }
};

int main()
{
    int x = Integer::atoi("322");
    float y = Integer::atof("2.33");
    cout << "x=" << x << " y=" << y << endl;

    return 0;
}