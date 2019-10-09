//practice6.cpp -- 输入汽车的耗油量，把每100 公里消耗？升转换为 每加仑多少英里。
#include<iostream>
using namespace std;
int main()
{
    cout << "Your fuel consumption (L/100km): ";
    double L;
    cin >> L;
    const double gallon = 3.875;
    const double mile = 62.14;
    double a = gallon *mile/L;
    cout << "Your fuel consumption (US) :" << a << " mpg";
    return 0 ;

}
