/******************
 * C++new和delete的使用
 * 
 * 基本数据类型的动态分配
 * ***************/
// new和delete已经完全包含malloc和free的功能，并且更强大、方便、安全。
// 使用动态分配内存时不能忘记释放内存，不要忘记出错处理！下面先看new和delete的基本使用方法。

#include <iostream>

using namespace std;

int main()
{
    // 基本数据类型
    int *i = new int;              //没有初始值
    int *j = new int(100);         //初始值为100
    float *f = new float(3.1415f); //初始值为3.14159
    cout << "  i = " << *i << endl;
    cout << "  j = " << *j << endl;
    cout << "  f = " << *f << endl;

    // 数组
    int *iArr = new int[3];
    for (int i = 0; i < 3; i++)
    {
        iArr[i] = (i + 1) * 10;
        cout << i << ":" << iArr[i] << endl;
    }

    // 释放内存
    delete i;
    delete j;
    delete f;
    delete[] iArr; //注意数组的删除方法

    return 0;
}
