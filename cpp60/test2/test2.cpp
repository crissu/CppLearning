/******************
 * C++名字空间
 * ***************/
#include<iostream>

using namespace std;

// 名字空间的定义

// namespace na
// {
//     void print(int n){
//         cout<<"na::print: "<<n<<endl;
//     }
// }

// namespace nb
// {
//     void print(int n){
//         cout<<"nb::print: "<<n<<endl;
//     }
// }

// namespace na
// {
//     void print2(int a, int b){
//         print(a);
//         print(b);
//     }
// }

// int main(){

//     na::print(3);        // 指定na下的print函数
//     nb::print(4);        // 指定na下的print函数
//     na::print2(5, 6);    // 指定na下的print2函数

//     return 0;
// }


// using的使用

// namespace na
// {
//     void print(int a) {
//         cout<<"na::print:"<<a<<endl;
//     }
// }

// namespace nb
// {
//     using namespace na;
//     void print2(int a, int b){
//         print(a);
//         print(b);
//     }

//     void print(int a){
//         cout<<"nb::print:"<<a<<endl;
//     }
// }

// namespace nc
// {
//     using nb::print2;
//     void print(int a, int b, int c){
//         print2(a, b);
//         nb::print(c);
//     }
// }

// int main ( )
// {
//     using namespace na;
//     print(2);    //na的print()函数
//     //using namespace nb;    //这样使用时，na和nb同时有效
//     //print(3);              //编译系统不清楚究竟调用na和nb中的哪一个，因为函数名和参数相同
//     using namespace nc;    //这样使用时，na和nc同时有效
//     print(4, 5, 6);        //nc的print()函数的参数与na中的参数不同，所以这儿不出错。
//     using nb::print;       //指定下面用的print()函数是nb的函数
//     print(7);
//     return 0;
// }


// 用别名指定名字空间

// namespace na {
//     namespace nb{
//         namespace nc{
//             int sum(int a, int b) {
//                 return a + b;
//             }
//         }
//     }
// }

// namespace A = na::nb::nc;

// int main(){
//     cout<<na::nb::nc::sum(1, 2)<<endl;
//     cout<<A::sum(1, 2)<<endl;
//     return 0;
// }


// 没有名字的名字空间
namespace na {
    namespace {
        int sum(int a, int b){
            return a + b;
        }
    }

    void calculate(int a, int b){
        cout << sum(a, b) << endl;
    }
}

int main(){
    na::calculate(1, 3);
    return 0;
}


