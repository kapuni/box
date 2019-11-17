// stone.cpp -- user-defined conversions
// compile with stonewt.cpp

#include <stdlib.h>
#include <iostream>
#include "stonewt.h"

using namespace std;

int main()
{
    Stonewt s[6] = { {275}, {288.22}, {26, 7} };
    for (int i = 3; i < 6; i++)
    {
        double pounds;
        cout << "Please enter the last 3 Stonewt class members(enter the entire pounds): \n";
        cout << "#" << i+1 << ": ";
        cin >> pounds;
        s[i] = pounds;
	}
    cout << "Enter finished!\n\n";
    cout << "So the whole 6 Stonewt class members are: \n";
    cout << "#1: " << s[0] << endl;
    cout << "#2: " << s[1] << endl;
    cout << "#3: " << s[2] << endl;
    cout << "#4: " << s[3] << endl;
    cout << "#5: " << s[4] << endl;
    cout << "#6: " << s[5] << endl;

    Stonewt mins = 65535;
    Stonewt maxs = 0;
    int num = 0;
    Stonewt flag(11,0);
    for (int i = 0; i < 6; i++)
    {
        if (s[i] < mins)
            mins = s[i];
        if (s[i] > maxs)
            maxs = s[i];
        if (s[i] >= flag)
            num++;
    }

    cout << "After comparation:\n";
    cout << "The maximum Stonewt class member is " << maxs << endl;
    cout << "The minimum Stonewt class member is " << mins << endl;
    cout << "There are " << num << " Stonewt class members bigger than 11 stones" << endl;
    cout << endl;
    cout << "Comparation finished!\nBye!\n";

    system("pause");
    return 0;
}

