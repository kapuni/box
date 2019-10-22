//calling.cpp -- defining ,prototyping ,and calling a function
#include<iostream>
void simple();
using namespace std;
int main()
{

    cout << "main will call the simple()function: \n";
    simple();
    return 0;
}

//¶¨Òåº¯Êý
void simple()
{
    cout << "I'm but a simple function.\n";
}
