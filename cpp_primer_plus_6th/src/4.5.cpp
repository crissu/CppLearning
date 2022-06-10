#include <iostream>
#include<string>

using namespace std;

struct CandyBar 
{
    std::string name;
    double weight;
    int calories;
};

int main() {
    CandyBar snack = {
        "derve",
        200,
        1000
    };

    cout << "name:"<< snack.name<<endl;
    cout << "weight:"<<snack.weight<<endl;
    cout<< "calories:"<<snack.calories<<endl;

    return 0;
}
