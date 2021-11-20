/******************
 * C++实例指针(this)
 * 
 * 运算符重载
 * ***************/
// “this”用于返回自身实例，在运算符重载中经常被使用。

#include <iostream>
#include <string>

using namespace std;

class rect
{
    int x1, x2, y1, y2;

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
    rect operator++(int)  // 注意这里 int 一定要加，需要制定类型
    {
        x1++, y1++, x2++, y2++;
        return *this; // 返回当前实例
    }
    void check(rect *obj){
        if (obj == this){
            cout<<"是"<<endl;
        }else{
            cout<<"否"<<endl;
        }
    }
};

int main(){
    rect r(1, 2, 3, 4);
    r.print();

    rect obj;
    obj = r++;
    obj.print();

    // 这两个结果都为否，说明重载时，中间生成了新的实例，只是实例类型一样而已
    obj.check(&r);
    r.check(&obj);

    return 0;
}