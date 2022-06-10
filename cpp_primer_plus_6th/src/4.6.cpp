#include <iostream>
#include <string>

using namespace std;

struct CandyBar
{
    std::string name;
    double weight;
    int calories;
};

int main()
{
    CandyBar candbar[3] = {
        {"derve", 200, 1000},
        {"chenpi", 100, 2000},
        {"feilieluo", 300, 3000},
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "name:" << candbar[i].name << endl;
        cout << "weight:" << candbar[i].weight << endl;
        cout << "calories:" << candbar[i].calories << endl;
    }

    return 0;
}
