//golf.cpp
#include<iostream>
#include<cstring>
#include"golf.h"

void setgolf(golf & g, const char * name, int hc)
{
    using namespace std;
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g)
{
    using namespace std;
    int temp = 1;

    cout << "The fullname is";
    cin.getline(g.fullname, Len);
    if(strcmp(g.fullname, "")== 0)
    {
        temp = 0;
        return temp;
    }
    else
    {
        cout << "The handicap is ";
        cin >> g.handicap;
        cin.get();
        return temp;
    }
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    using namespace std;
    cout << " The fullname is " << g.fullname << endl;
    cout << "The handicap is " << g.handicap << endl;
}
