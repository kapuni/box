//practice6.cpp -- ���������ĺ���������ÿ100 �������ģ���ת��Ϊ ÿ���ض���Ӣ�
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
