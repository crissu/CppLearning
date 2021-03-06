/******************
 * C++静态类成员
 * 
 * 类的静态常数
 * ***************/
// 和静态成员变量类似功能，当不允许修改时，要定义成常数。

#include <iostream>
#include <string>

using namespace std;

class Integer
{
public:
    static const int MAX_LEN = 100;
    static const int MIN_LEN = 10;
};

//以下的申明不需要
//int Integer::MAX_LEN;
//int Integer::MIN_LEN;

int main()
{
    cout << "MAX_LEN = " << Integer::MAX_LEN << endl;
    cout << "MIN_LEN = " << Integer::MIN_LEN << endl;

    return 0;
}