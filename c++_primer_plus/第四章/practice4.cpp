//practice4.cpp -- using string and header<string>
#include<iostream>
#include<string>
int main()
{
    using namespace std;
    string lname;
    string fname;
    string fullname;
    cout << "Enter your first name: ";
    cin >> fname;
    cout << "Enter your last name: ";
    cin >> lname;
    fullname = fname + ", " +lname;
    cout << "Here's the information in a single string :" << fullname << endl;
    return 0;
}
