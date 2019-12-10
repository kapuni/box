//
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;
void show(string & s);

int main()
{
    //Mat
    list<string> Mat;
    cout << "---------Mat's friends---------" << endl;
    cout << "Enter the name (quit to quit):" << endl;
    string temp1;
    getline(cin, temp1);
    while (temp1 != "quit")
    {
        Mat.push_back(temp1);
        cout << "Enter the name(quit to quit):\n";
        getline(cin,temp1);
    }
    Mat.sort();
    cout << "Here are Mat's friends: \n";
    for_each(Mat.begin(), Mat.end(),show);
    cout << endl;

    //Pat
     list<string> Pat;
    cout << "---------Pat's friends---------" << endl;
    cout << "Enter the name (quit to quit):" << endl;
    string temp2;
    getline(cin, temp2);
    while (temp2 != "quit")
    {
        Pat.push_back(temp2);
        cout << "Enter the name(quit to quit):\n";
        getline(cin,temp2);
    }
    Pat.sort();
    cout << "Here are Pat's friends: \n";
    for_each(Pat.begin(), Pat.end(),show);
    cout << endl;

    //all
    cout << "-------friend----------\n";
    Mat.splice(Mat.end(), Pat);
    Mat.sort();
    Mat.unique();
    cout << "All friend:\n";
    for_each(Mat.begin(), Mat.end(), show);

    return 0;
}

void show(string & s)
{
    cout << "friend's name:   " << s << endl;
}
