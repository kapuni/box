
#include <iostream>
#include <string>
#include "wine.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

Wine::Wine(const char *l, int y)
{
    label = l;
    yearnumber = y;
    ArrayInt a(y);
    ArrayInt b(y);
    number = std::make_pair(a, b);
}

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
{
    label = l;
    yearnumber = y;
    ArrayInt a(y);
    ArrayInt b(y);
    for (int i=0;i< y; ++i)
    {
        a[i] = yr[i];
        b[i] = bot[i];

    }
    number = std::make_pair(a, b);
}

void Wine::GetBottle()
{
    cout << "Enter " << label << " data for " << yearnumber << "year(s): \n";
    number.first.resize(yearnumber);
    number.second.resize(yearnumber);
    for (int i = 0;i< yearnumber;++i)
    {
        cout << "Enter year: ";
        cin >> number.first[i];
        cout << "Enter bottles for that year: ";
        cin >> number.second[i];
    }
}

void Wine::Show()
{
    cout << "Wine :" << label << endl;
    cout << " Year Bottles" << endl;
    for (int i = 0;i <yearnumber; i++)
    {
        cout << " " << number.first[i] << " " << number.second[i] << endl;

    }
}

const std::string & Wine::Label()
{
    return label;
}

int Wine::sum()
{
    int count = 0;
    for (int i = 0;i< yearnumber; i++)
        count += number.second[i];
    return count;
}
