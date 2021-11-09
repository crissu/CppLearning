#include <iostream>
#include <string>

using namespace std;

/******************
 * C++成员函数和运算符的重载
 * ***************/

// 构造函数的重载
// class stuff {
//     string name;
//     int age;
// public:
//     stuff(){
//         cout<<name<<"---"<<age<<endl;
//         name = "空";
//         age = 0;
//         cout<<name<<"---"<<age<<endl;
//     }
//     stuff(string n, int a):name(n),age(a){
//         cout<<name<<"---"<<age<<endl;
//     }
//     string getName(){
//         return name;
//     }
//     int getAge(){
//         return age;
//     }
// };

// int main(){
//     stuff st2;
//     stuff st1("c++", 30);

//     return 0;
// }

// 运算符重载
/*
//单目运算符
成员函数：      返回值类型  operator  运算符  () ;
普通函数：      返回值类型  operator  运算符  (对象的类型) ;

//双目运算符
成员函数：      返回值类型  operator  运算符  (对象的类型) ;
普通函数：      返回值类型  operator  运算符  (对象的类型1, 对象的类型2) ;

//函数调用
成员函数：      返回值类型  operator  (任意的参数列) ;

//数组元素
成员函数：      返回值类型  operator[]  (参数类型) ;

//增1/减1运算符
成员函数：      返回值类型  operator  运算符  (int) ;
普通函数：      返回值类型  operator  运算符  (对象的类型, int) ;
*/
// class stuff {
//     string name;
//     int age;
// public:
//     stuff(string n, int a):name(n), age(a){
//         cout<<name<<"---"<<age<<endl;
//     }
//     string getName(){
//         return name;
//     }
//     int getAge(){
//         return age;
//     }
//     void operator +(int x);
//     void operator +(string s);
// };

// void stuff::operator + (int x){
//     age = age+x;
// }

// void stuff::operator +(string s){
//     name = name + s;
// }

// int main(){
//     stuff st2("C语言中文网", 3);
//     st2 + 2;
//     st2 + ".C++60分钟入门教程";
//     cout<<st2.getName() << "---" << st2.getAge()<<endl;

//     return 0;
// }

// 拷贝构造函数和赋值运算符
// class stuff
// {
//     string name;
//     int age;

// public:
//     stuff(string n, int a) : name(n), age(a)
//     {
//         cout << "构造函数  " << name << age << endl;
//     }
//     string getName()
//     {
//         return name;
//     }
//     int getAge()
//     {
//         return age;
//     }
//     stuff &operator=(stuff &x);             //赋值运算符重载
//     stuff(stuff &x) : name(x.name), age(20) //拷贝构造函数重载
//     {
//         cout << "拷贝构造函数  " << name << age << endl;
//     }
// };
// stuff &stuff::operator=(stuff &x)
// {
//     age = x.age;
//     cout << "赋值运算符  " << name << age << endl;
//     return *this;
// }
// int main()
// {
//     stuff st("C语言中文网", 3);     //调用通常的构造函数
//     stuff st1("C++ 60入门教程", 2); //调用通常的构造函数
//     st1 = st;                       //因为不产生新的实例，所以调用的是赋值运算符
//     stuff st2 = st;                 //因为产生新的实例，所以调用的是拷贝构造函数
//     cout << st.getName() << st.getAge() << endl;
//     cout << st1.getName() << st1.getAge() << endl;
//     cout << st2.getName() << st2.getAge() << endl;
//     return 0;
// }

// 类型转换
// class stuff{
//     string name;
//     int age;
//     public:
//     stuff(string n, int a):name(n),age(a){}

//     string getName(){
//         return name;
//     }
//     int getAge(){
//         return age;
//     }
//     operator int(){
//         return age;
//     }
//     operator string(){
//         return name;
//     }
// };

// int main(){
//     stuff st("C语言中文网", 3);
//     string m_name = st;
//     int m_age = st;
//     cout<<m_name<<endl;
//     cout<<m_age<<endl;

//     return 0;
// }

class stuff
{
    string name;
    int age;

public:
    stuff(string n, int a) : name(n), age(a)
    {
        cout << "构造函数  " << name << age << endl;
    }

    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    stuff &operator=(stuff &x);
    stuff(stuff &x) : name(x.name), age(20)
    {
        cout << "拷贝构造函数  " << name << age << endl;
    }
};

stuff &stuff::operator=(stuff &x)
{
    age = x.age;
    cout << "赋值运算符  " << name << age << endl;
    return *this;
}

int main(){
    stuff st("c语言", 3);
    stuff st1("c++语言", 2);
    st1 = st;
    stuff st2 = st;
    cout << st.getName() << st.getAge() << endl;
    cout << st1.getName() << st1.getAge() << endl;
    cout << st2.getName() << st2.getAge() << endl;

    return 0;
}