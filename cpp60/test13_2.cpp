/******************
 * C++实例指针(this)
 * 
 * 判断一个对象是否为自己
 * ***************/
// 对象（即实例）可以通过参数传来传去，有时需要判断一下用对象是否与自己是同一实例，
// 可以用“if (&obj == this) { ... }”

#include <iostream>
#include <string>

using namespace std;

class base
{
public:
    void check(base *obj)
    {
        if (obj == this)
        {
            cout << "这是当前的对象" << endl;
        }
        else
        {
            cout << "这不是当前的对象" << endl;
        }
    }
};

class derive:public base{
    public:
        base* getBase(){
            base *p = this;  // 强制转换成父类地址
            return p;
        }
};

int main(){
    base ba;
    derive de;
    base *p1 = de.getBase();
    base *p2 = &ba;

    p1->check(&ba);
    p2->check(&ba);

    return 0;
}








