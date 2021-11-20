#include <iostream>
#include <string>
using namespace std;

/******************
 * C++派生类中调用基类成员
 * 
 * 多重继承的调用方法
 * ***************/

class CBase1
{
    string name;

protected:
    string id;

public:
    CBase1(string s1, string s2) : name(s1), id("base1-" + s2) {}
    void show()
    {
        cout << "name:" << name << endl;
        cout << "id:" << id << endl;
    }
};

class CBase2{
    int salary;
    protected:
    string id;
    public:
    CBase2(int y, string s2):salary(y), id("base2-"+s2){}
    void show(){
        cout << "salary:" << salary << endl;
        cout << "id:" << id << endl;
    }
};

class CDerive:public CBase1, public CBase2{
    string id;
    int age;
    public:
    CDerive(string s1, int a, string s2, int y):age(a),id("cderive-"+s1),
    CBase1(s1, s2), CBase2(y, s2){}

    void show(){
        cout<<"id:"<<id<<endl;
        cout<<"age:"<<age<<endl;
        CBase1::show();
        CBase2::show();
        cout << "bas1: " << CBase1::id << endl;  //调用CBase1的成员变量
        cout << "bas2: " << CBase2::id << endl;  //调用CBase2的成员变量
    }
};

int main()
{
    CDerive d("crissu", 3, "2019", 5000);
    d.show();

    return 0;
}
