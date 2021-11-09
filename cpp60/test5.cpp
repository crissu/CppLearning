#include <iostream>

using namespace std;

/******************
 * C++类与对象
 * ***************/

// 构造函数和析构函数

// class CA {
//     int a;
// public:
//     CA(){
//         a = 0;
//         cout<< "构造函数" << a << endl;
//     }
//     ~CA(){
//         cout<< "析构函数" << a << endl;
//     }
//     void setA(int x ){
//         a = x;
//     }
//     void print(){
//         cout<< "print:"<< a << endl;
//     }
// };

// int main(){
//     CA ca;
//     ca.print();
//     ca.setA(10);
//     ca.print();

//     return 0;
// }

// 成员函数的定义和声明分开
// class CA
// {
//     int a;

// public:
//     CA();
//     ~CA();
//     void setA(int x);
//     void print();
// };

// int main()
// {
//     CA ca;
//     ca.print();
//     ca.setA(10);
//     ca.print();

//     return 0;
// }

// CA::CA()
// {
//     a = 0;
//     cout << "构造函数" << a << endl;
// }
// CA::~CA()
// {
//     cout << "析构函数" << a << endl;
// }
// void CA::setA(int x)
// {
//     a = x;
// }
// void CA::print()
// {
//     cout << "print:" << a << endl;
// }


// 生成实例的3种方法
int main(){
    string strA("crissu 贼拉帅");
    cout<<strA<<"  "<<strA.length()<<endl;

    string strB;
    strB = string("C++60分钟入门教程");
    cout<<strB<<"  "<<strB.length()<<endl;

    string *strC;
    strC = new string("crissu最帅，你说是不是吧");
    cout<<*strC<<"  "<< strC->length()<<endl;
    delete strC;

    return 0;
}





