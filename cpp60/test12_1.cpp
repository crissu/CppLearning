/******************
 * C++多态的应用
 * 
 * 求面积
 * ***************/
// 基类里定义三个函数：设置区域数据setData()、取区域数据getData、求面积(虚函数)getArea。
// 所谓数据，定义2个成员变量dim1和dim2，对于长方形来说是长和宽，对于三角形来说是底和高。

#include <iostream>
#include <string>

using namespace std;

class area
{
    double dim1, dim2;

public:
    // 设置数据
    void setData(double d1, double d2)
    {
        dim1 = d1, dim2 = d2;
    }

    // 取数据
    void getData(double &d1, double &d2)
    {
        d1 = dim1, d2 = dim2;
    }

    // 求面积
    virtual double getArea() = 0; // 纯虚函数
};

// 长方形
class rectangle:public area{
    public:
    double getArea(){
        double d1, d2;
        getData(d1, d2);
        return d1 * d2;
    }
};

// 三角形
class triangle:public area{
    public:
    double getArea(){
        double d1, d2;
        getData(d1, d2);
        return d1 * d2 / 2;
    }
};


int main(){
    area *p;
    rectangle r;
    triangle t;

    r.setData(2, 3);
    t.setData(3, 6);

    p = &r;
    cout<<"长方形面积:"<<p->getArea()<<endl;
    p = &t;
    cout<<"三角形面积:"<<p->getArea()<<endl;

    return 0;
}