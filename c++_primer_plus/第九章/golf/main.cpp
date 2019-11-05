//main.cpp
#include <iostream>
#include"golf.h"

using namespace std;

int main()
{
    golf g[10];
    int count = 0;
    cout << "Enter the information of golf player: " << endl;
    while((count < 10) && (setgolf(g[count])))
    {
        cout << "Next golf player: \n";
        count ++;
    }

    cout << "\nShow all golf player information: \n";
    for (int i=0; i<count; i++)
    {
        showgolf(g[i]);
    }

    cout << "\nReset the value of handicap, and show all golf player information:\n";
    for (int i=0; i< count; i++)
    {
        handicap(g[i], i+5);
        showgolf(g[i]);
    }
    return 0;
}
