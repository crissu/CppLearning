#include <iostream>
#include<cstring>

using namespace std;

int main() {
    char firstname[20], lastname[20];
    char finalname[50];

    cout << "Enter firstname: ";
    cin.getline(firstname, 20);

    cout << "Enter lastname: ";
    cin.getline(lastname, 20);

    strcpy(finalname, lastname);
    strcat(finalname, ", ");
    strcat(finalname, firstname);

    cout<<"finalname:"<<finalname<<endl;
    return 0;
}
