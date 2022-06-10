#include <iostream>
#include<string>

using namespace std;

int main() {
    string name;
    string dessert;
    cout << "Enter name:\n";
    getline(cin, name);

    cout<<"Enter dessert:\n";
    getline(cin, dessert);

    cout << "I have delicious " << dessert;
    cout << " for you,  " << name << ".\n";

    return 0;
}
