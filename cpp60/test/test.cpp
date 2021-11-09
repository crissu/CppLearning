#include<iostream>
#include "test.h"
using namespace std;

CA::CA(){
    a = 0;
    cout<< "构造函数: " << a << endl; 
}

CA::~CA(){
    cout<<"析构函数: "<< a << endl;
}

void CA::setA(int x){
    a = x;
}

void CA::print(){
    cout<< "print: "<< a << endl;
}

int main(){
    CA ca;
    ca.setA(10);
    ca.print();

    return 0;
}