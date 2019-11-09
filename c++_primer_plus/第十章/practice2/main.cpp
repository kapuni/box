#include <iostream>
#include <string>
#include <cstring>
#include "person.h"



int main()
{
    using std::cout;
    using std::endl;
    Person one;
    one.Show();
    cout << "\n";
    one.FormalShow();
    cout << endl;

    Person two("Smythecraft");
    two.Show();
    cout << endl;
    two.FormalShow();
    cout << endl;

    Person three("Dimwdiddy", "Sam");
    three.Show();
    cout << endl;
    three.FormalShow();
    cout << endl;
    return 0;
}
