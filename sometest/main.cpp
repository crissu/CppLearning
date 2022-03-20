#include <iostream>

using namespace std;

struct cat
{
    string name;
    string type;
};

struct dog
{
    string name;
    string type;
};

int main()
{
    cat cc = cat{"cccc", "cat"};
    dog dd = dog{"dddd", "dog"};
    cout << cc.name << " " << cc.type << endl;
    cout << dd.name << " " << dd.type << endl;
    int any = 0;
    cout << sizeof(any) << endl;

    return 0;
}
