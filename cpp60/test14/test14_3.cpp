/******************
 * C++友元函数(friend)
 * 
 * 运算符重载中使用友元
 * ***************/
// 下面将上一节最后一个例子稍作修改，操作符重载由类的函数改为全局函数，
// 也就是说，这个运算符不是这个类的，而是正常使用的操作符。注意重载函数的写法与上一节略有不同。
// 不过，改为友元方式其实并没有必要，纯粹是为了讲解“友元”的用法。

#include <iostream>
#include <string>

using namespace std;

class rect
{
    int x1, y1, x2, y2; // 矩形坐标
public:
    rect()
    {
        x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    }
    rect(int m1, int n1, int m2, int n2)
    {
        x1 = m1, y1 = n1, x2 = m2, y2 = n2;
    }
    void print()
    {
        cout << "  x1=" << x1;
        cout << "  y1=" << y1;
        cout << "  x2=" << x2;
        cout << "  y2=" << y2;
        cout << endl;
    }
    // rect operator++(int); // 这是类的运算符的重载
    friend rect operator++(rect &obj, int); // 这是全局运算符的重载
};

rect operator++(rect &obj, int)
{
    obj.x1++, obj.y1++;
    obj.x2++, obj.y2++;
    return obj;
}

int main()
{
    rect r(1, 2, 3, 4);
    r.print();

    rect obj;
    obj = r++;
    obj.print();

    return 0;
}
