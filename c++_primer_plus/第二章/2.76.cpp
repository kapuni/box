//2.71.cpp -- 显示小时和分钟
#include<iostream>

using namespace std;
void time(int h,int m);

int main()
{
    cout << "Enter the number of hours: " << endl;
    int h;
    cin >> h;
    cout << "Enter the number of minutes: " << endl;
    int m;
    cin >> m;
    time(h,m);
    return 0;
}
void time(int h, int m)
{
    cout << "Time:" << h << ":" << m << endl;
}
