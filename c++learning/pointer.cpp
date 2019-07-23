#include <iostream>

using namespace std;

int main()
{
    int age =19;
    int *pAge = &age;
    double gpa = 2.7;
    double *pGpa = &gpa;
    string name = "kapuni";
    string *pName = &name;

    cout << &*&gpa << endl;
    cout << *pAge;
    /*
    cout << "Age: " << &age << endl;
    cout << "GPA: " << &gpa << endl;
    cout << "Name: " << &name << endl;
    */
    return 0;
}
