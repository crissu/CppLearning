/******************
 * C++构造函数、explicit、类合成
 * 
 * 只有一个成员变量的类
 * ***************/
// 当只有一个成员变量时，有一些不太注意的缺省转换发生，这是编译器造成的。

// 编译的时候有 warning:ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
// 但是能够编译通过

#include <iostream>
#include <cstdlib>

using namespace std;

class classA
{
    int x;

public:
    classA(int x) { this->x = x; }
    classA(char *x) { this->x = atoi(x); }
    int getX() { return x; }
};
int main()
{
    classA ca(5); //正常调用构造函数
    cout << "x = " << ca.getX() << endl;
    ca = 100; //缺省调用classA(100)
    cout << "x = " << ca.getX() << endl;
    ca = "255"; //缺省调用classA("255")
    cout << "x = " << ca.getX() << endl;
    return 0;
}