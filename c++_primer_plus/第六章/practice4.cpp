//practice4.cpp -- creating a struct bof ; a menu with some choice
#include<iostream>

using namespace std;
const int strSize = 20;
const int number = 5;
void display_fullname();
void display_title();
void display_bopname();
void display_perference();
int i;
struct bop
{
    char fullname[strSize];
    char title[strSize];
    char bopname[strSize];
    int preference;
};
bop a[number] =
{
     {
         "Wimp Macho",
         "Boss",
         "WM",
         0
     },
     {
         "Raki Rhodes",
         "Manager",
         "Junior Programmer",
         2
     },
     {
         "Celia Laiter",
         "MiPS",
         "CL",
         1
     },
     {
         "Hoppy Hipman",
         "Analyst Trainee",
         "AT",
         1
     },
     {
         "Pat Hand",
         "Student",
         "LOOPY",
         2
     }
};
int main()
{
    cout << "Benevolent Order of Programmers Report\n"
    << "a. display by name       b. display by title \n"
    << "c. display by bopname    d. display by preference\n"
    << "quit\n";
    cout << "Enter your choice: \n";
    char ch;
    ch = cin.get();
    while (ch != 'q')
    {
        switch(ch)
        {
        case 'a':
            display_fullname();
            break;
        case 'b':
            display_title();
            break;

        case 'c':
            display_bopname();
            break;
        case 'd':
            display_perference();
            break;
        }
        if (ch != 'q')
            cout << "Next choice";
    }
    cout << "Bye!\n";
    return 0;
}

void display_fullname()
{
    int i;
    for (i=0;i<number;i++)
    {
         cout << a{i}.fullname << endl;
    }

}

void display_title()
{
    for (i=0;i<number;i++)
        cout << a{i}.title <<endl;
}

void display_bopname()
{
    for (i=0;i<number;i++)
        cout << a{i}.bopname <<endl;
}

void display_preference()
{
    if (a[i].preference == 0)
        cout << a[i].fullname << endl;
    else if (a[i].preference == 1)
        cout << a[i].title << endl;
    else if (a[i].preference == 2)
        cout << a[i].bopname << endl;
}
