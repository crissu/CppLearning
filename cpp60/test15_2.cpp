/******************
 * C++构造函数、explicit、类合成
 * 
 * 用explicit禁止默认转换
 * ***************/
// 默认转换带来一定的方便，同时也造成不必要的失误，为了防止失误，可以在构造函数前加“explicit”。

#include <iostream>
#include <cstdlib>

using namespace std;

class classA
{
    int x;

public:
    explicit classA(int x)
    {
        this->x = x;
    }
    explicit classA(char *x)
    {
        this->x = atoi(x);
    }
    int getX()
    {
        return x;
    }
};

int main()
{
    classA ca(5); //正常调用构造函数
    cout << "x = " << ca.getX() << endl;
    classA caa("777"); //正常调用构造函数
    cout << "x = " << caa.getX() << endl;
    // ca = 100; //编译错误
    // cout << "x = " << ca.getX() << endl;
    // ca = "255"; //编译错误
    // cout << "x = " << ca.getX() << endl;
    return 0;
}
