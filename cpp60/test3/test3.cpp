/******************
 * C++缺省参数和函数重载
 * ***************/
#include<iostream>

using namespace std;

// 参数的缺省值
// #include <iostream>
// using namespace std;
// int sum(int x=0, int y=100, int z=0) { return x+y+z; }
// //int sum(int x, int y=100, int z=0) { ... }   //这是正确的
// //int sum(int x, int y, int z=0) { ... }       //这也是正确的
// //int plus(int x, int y=100, int z) { ... }    //这是错误的
// int main()
// {
//     cout << sum() << endl;
//     cout << sum(6) << endl;
//     cout << sum(6, 10) << endl;
//     cout << sum(6, 10, 20) << endl;
//     return 0;
// }


// 函数的重载
// float fun(float a);
// double fun(double a);

// int main(){
//     float f = 12.64;
//     double d = 33.99;
//     cout<<fun(f)<<endl;
//     cout<<fun(d)<<endl;
//     return 0;
// }

// float fun(float a){
//     return a / 2.0;
// }


// double fun(double a){
//     return a / 3.0;
// }


// 设计时的重载错误
// 上面的例子中，设计时并没有问题，调用时类型自动转换时发生了二义性。
// #include <iostream>
// using namespace std;
// int fun(int a, int b);
// int fun(int a, int &b);
// int main ( )
// {
//     int x=1, y=2;
//     cout << fun(x, y) << endl;    //这句编译时出错
//     return 0;
// }
// int fun(int a, int b);
// {
//     return a + b;
// }
// int fun(int a, int& b);
// {
//     return a - b;
// }


// 重载函数的地址
void space(int count);
void space(int count, char ch);

int main ( )
{
    //有一个整型参数的函数指针
    void (*fp1)(int);
    //有一个整型参数、一个字符型参数的函数指针
    void (*fp2)(int, char);
    fp1 = space;    //取space(int)函数的地址
    fp2 = space;    //取space(int, char)函数的地址
    fp1(20);        //输出20个空格
    cout << "|" << endl;
    fp2(20, '=');   //输出20个等号
    cout << "|" << endl;
    return 0;
}
//输出count个空格字符
void space(int count)
{
    for ( ; count; count--) cout << ' ';
}
//输出count个ch字符
void space(int count, char ch)
{
    for ( ; count; count--) cout << ch;
}









