//practice3.cpp -- using char and header <cstring>
#include<iostream>
#include<cstring>
int main ()
{
    using namespace std;
    const  int Size = 20;
    char fname[Size];
    char lname[Size];
    char fullname[2*Size + 1];

    cout << "Enter your first name: ";
    cin >> fname;
    cout << "Enter your last name:";
    cin >> lname;
    strncpy(fullname,lname,Size);
    strcat(fullname, ", ");
    strncat(fullname, fname, Size);
    fullname[Size - 1] = '\0';
    cout << "Here's the information in a single string :" << fullname << endl;
    return 0;
}
