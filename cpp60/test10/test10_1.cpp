/******************
 * C++多重继承的问题
 * 
 * 多重继承的先后问题
 * ***************/
// 这个例子与案例实现结果不相似，孙子类不能通过取爷爷的域来读取爷爷的元素
// 必须通过父亲类来获取爷爷的元素

// 当前实例是CBase的“孙子”，而“父亲”有2个，每个“父亲”都将“爷爷”复制了一份。
// 如果不指定哪个“父亲”的“父亲”，默认将第一个继承的“父亲”的“父亲”当作“爷爷”

#include <iostream>
#include <string>
using namespace std;

class CBase {
public:
    string id;
};
class CDerive1 : public CBase {
public:
    void show1() {
        cout << "CDerive1: " << id << endl;
    }
};
class CDerive2 : public CBase {
public:
    void show2() {
        cout << "CDerive2: " << id << endl;
    }
};
class CSon : public CDerive2, public CDerive1 { };
int main ( )
{
    CSon s;
    s.CDerive1::id = "WD8503026";
    s.CDerive2::id = "WD8503027";
    // s.CBase::id = "WD8503025";
    s.show1();
    s.show2();
    // cout << "BASE: " << s.CBase::id << endl;
    return 0;
}
