#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //int age;
    string name;
    cout << "Enter your name: ";
    //cin >> age;
    getline(cin, name);
    //cout << "You are " << age << " years old";
    cout << "Hello " << name;

    return 0;

}
