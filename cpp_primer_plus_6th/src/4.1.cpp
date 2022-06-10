#include <iostream>

using namespace std;

int main() {
    char firstName[40];
    char secondName[40];
    char grade;
    int age;

    cout<<"what is your first name:";
    cin.getline(firstName, 40);
    
    cout<<"what is your second name:";
    cin.getline(secondName, 40);
    
    cout<<"what is your grade:";
    cin>>grade;

    cout<<"what is your age:";
    cin>>age;

    cout << "Name: " << secondName << ", " << firstName << endl;
    cout << "Grade: " << char(grade+1) << "\n";
    cout << "Age: " << age << endl;

    return 0;
}
