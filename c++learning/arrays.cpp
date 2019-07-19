#include <iostream>
#include <cmath>

using namespace std;

void sayHi(string name, int age);

int main()
{
    /***
    int luckyNums[20] = {5, 16, 56, 48, 78, 89, 2};
    luckyNums[0] = 100;
    cout << luckyNums[0] << endl;
    ***/

    cout << "Top " << endl;
    sayHi("Mike", 60);
    sayHi("Kapuni", 23);
    sayHi("Tom", 19);
    cout << " bottom" << endl;

    return 0;
}

void sayHi(string name, int age)
{
    cout << "Hello " << name << " you are " << age << endl;
}
