//saying2.cpp -- uses pointers to objects
//compile with string1.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "string1.h"
const int Arsize = 10;
const int MaxLen = 81;
int main()
{
    using namespace std;
    String name;
    cout << "Hi ,What's your name?\n >>";
    cin >> name;

    cout << name  << ", please enter up to " << Arsize
    << " short sayings <empty line to quit>: \n";
     String sayings[Arsize];
     char temp[MaxLen];
     int i;
     for (i = 0;i < Arsize; i++)
     {
        cout << i+1 << ":";
        cin.get(temp, MaxLen);
        while (cin && cin.get()!= '\n')
            continue;
        if (!cin || temp[0] == '\0')
            break;
        else
            sayings[i] = temp;
     }
     int total = i;

     if (total > 0)
     {
         cout << "Here are your sayings:\n";
         for (i = 0; i < total; i++)
            cout << sayings[i] << endl;

         //use pointers to keep track of shortest , first strings
         String * shortest  = &sayings[0];
         String * first = &sayings[0];

         for (i = 1; i < total; i++)
    {
        if (sayings[i].length() < shortest->length())
            shortest = &sayings[i];
        if (sayings[i] < *first)
            first = &sayings[i];
    }
    cout << "Shortest saying:\n" << * shortest << endl;
    cout << "First alphabetically:\n " << * first << endl;

    srand(time(0));
    int choice = rand()% total;

    //use new
    String * favorite = new String(sayings[choice]);
    cout << "My favorite saying: \n" << *favorite << endl;
    delete favorite;
     }
     else
        cout << "No much to saying, eh? \n";
     cout << "Bye.\n";
     return 0;
}
