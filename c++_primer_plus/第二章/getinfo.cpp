// getinfo.cpp -- input and output

#include <iostream>


using namespace std;

int main()
{
    int carrots;

    cout << "How many carrots do you have? " <<  endl;
    cin >> carrots;              // input
    cout << "Here are two more. ";
    carrots = carrots + 2;
    cout << "Now you have" << carrots << " carrots." << endl;   // concatenate output
    return 0;
}
