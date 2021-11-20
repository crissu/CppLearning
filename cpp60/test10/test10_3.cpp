/******************
 * C++多重继承的问题
 * 
 * 虚继承
 * ***************/
// 解决以上问题只要用C++的“虚继承”就可以了。“虚继承”就是在实例中，基类不管继承多少个，只复制一份。

#include <iostream>
#include <string>
using namespace std;

class CBase
{
public:
    string id;
};

class CDerive1:virtual public CBase{
    public:
    void show1(){
        cout<<"CDerive1:"<<id<<endl;
    }
};

class CDerive2:virtual public CBase{
    public:
    void show2(){
        cout<<"CDerive2:"<<id<<endl;
    }
};

class CSon:public CDerive2, public CDerive1{};

int main(){
    // CSon s;
    // s.CDerive1::id = "wc001";
    // s.CDerive2::id = "wc002";
    // s.CBase::id = "wc003";
    // s.show1();
    // s.show2();
    // cout<<"BASE:"<<s.CBase::id<<endl;

    CSon s;
    cout <<  &s << endl;
    cout <<  "---------" << endl;
    CDerive1 *pd1 = &s;
    cout <<  pd1 << endl;
    CDerive2 *pd2 = &s;
    cout <<  pd2 << endl;
    cout <<  "---------" << endl;
    CBase *pb1 = pd1;
    cout <<  pb1 << endl;
    CBase *pb2 = pd2;
    cout <<  pb2 << endl;

    return 0;
}

