#include <iostream>
#include<string>

using namespace std;

int main() {
    string firstname, lastname;
    string finalname;

    cout << "enter firstname: ";
    getline(cin, firstname);
    cout << "enter lastname: ";
    getline(cin, lastname);

    finalname = lastname + ", " + firstname;

    cout << "hello, "<<finalname << endl;

    return 0;
}
