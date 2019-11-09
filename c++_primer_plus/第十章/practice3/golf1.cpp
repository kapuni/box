//golf1.cpp
#include<iostream>
#include<cstring>
#include"golf1.h"

Golf::Golf(const std::string name, int hc)
{
    fullname = name;
    handicap = hc;
}

int Golf::setgolf()
{
    using namespace std;
    int handicap = 0;

    cout << "The fullname is: ";
    getline(cin, fullname);
    cout << "The handicap is: ";
    cin >> handicap;

    Golf g(fullname, handicap);
    *this = g;
    return fullname == "" ? 0 : 1;


}


void Golf::sethandicap(const int hc)
{
    handicap = hc;
}

void Golf::showgolf() const
{
    using namespace std;
    cout << " The fullname is " << fullname << endl;
    cout << "The handicap is " << handicap << endl;
}
