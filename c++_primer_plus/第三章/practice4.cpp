//practice.cpp -- 输入秒数转换为天。小时。分钟。秒
#include<iostream>
using namespace std;
int main()
{
    cout << "Enter the number seconds: " ;
    int a;
    cin >> a;
    const int M = 60;
    const int H = 24;
    int days = a / M /M/H;
    int hours = (a- days * 3600*24)/M/M;
    int minutes = (a - days *M*M*H-hours*3600)/M;
    int seconds  = (a - days * 3600 * 24 -hours*3600 - minutes * 60);
    cout << a << " seconds = " << days << " days, " << hours<< " hours, "<< minutes << " minutes, " << seconds << " seconds."<< endl;
    return 0 ;
}
