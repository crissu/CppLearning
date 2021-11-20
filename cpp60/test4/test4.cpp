/******************
 * C++引用
 * ***************/
#include <iostream>

using namespace std;

// 独立引用
// int main() {
//     int a ;
//     int &b = a;    //b和a实际上是同一变量
//     b = 100;       //b赋值为100，也就是a赋值为100
//     cout << a << endl;
//     //a的地址和b的地址应该是完全一样
//     cout << &a << endl;
//     cout << &b << endl;
//     /*-------▼下面代码有错，注释后才能运行▼-----------
//     int x[] = {12,15,20} ;
//     int &y = x;    //错误：数组、指针不能被引用
//     int x1;
//     int &y1;    //错误：引用时必须初始化
//     y1 = x1;
//     -------▲上面代码有错，注释后才能运行▲-----------*/
//     return 0;
// }

// 函数的参数引用
//                                                 //|右边为指针作参数的代码，仅作比较用。
// void swap(int &x, int &y);                      //|void swap(int *x, int *y);
//                                                 //|
// int main ( )                                    //|
// {                                               //|
//     int i = 12;                                 //|
//     int j = 25;                                 //|
//     cout << "i=" << i << "   j=" << j << endl;  //|
//                                                 //|
//     swap(i, j);                                 //|swap(&i, &j);
//     cout << "i=" << i << "   j=" << j << endl;  //|
//                                                 //|
//     return 0;                                   //|
// }                                               //|
//                                                 //|
// void swap(int &x, int &y)                       //|void swap(int *x, int *y)
// {                                               //|{
//     int t;                                      //|    int t;
//                                                 //|
//     t = x;                                      //|    t = *x;
//     x = y;                                      //|    *x = *y;
//     y = t;                                      //|    *y = *x;
// }                                               //|}


// 对象引用作参数

// class myclass {
//     int who;
// public:
//     myclass(int n) {
//         who = n;
//         cout << "构造函数调用" << who << endl;
//     }
//     ~myclass() {
//         cout << "析构函数调用" << who << endl;
//     }
//     int id() {
//         return who;
//     }
// };
// void f1(myclass o) {    //普通变量方式传递参数
//     cout << "外部函数调用" << o.id() << endl;
// }
// void f2(myclass *o) {    //指针方式传递参数
//     cout << "外部函数调用" << o->id() << endl;
// }
// void f3(myclass &o) {    //引用方式传递参数
//     cout << "外部函数调用" << o.id() << endl;
// }
// int main ( )
// {
//     myclass x1(1);
//     f1(x1);
//     cout << "-------" << endl;
//     myclass x2(2);
//     f2(&x2);
//     cout << "-------" << endl;
//     myclass x3(3);
//     f3(x3);
//     cout << "-------" << endl;
//     return 0;
// }


// 作为函数返回值的引用类型
int &f();
int x;

int main(){
    f() = 100;
    cout<<x<<endl;
    f() = 200;
    cout<<x<<endl;
    return 0;
}

int &f(){
    return x;
}






