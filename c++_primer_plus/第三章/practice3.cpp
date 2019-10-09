//practice.cpp -- 输入度。分。秒的维度 转换为 以度为单位
#include<iostream>
using namespace std;
int main()
{
    cout << "Enter a latitude in degrees, minutes, seconds: \n";
    cout << "Fist, enter the degrees: ";
    int degrees;
    cin >> degrees;
    cout << "Next, enter the minutes of arc: ";
    int minutes;
    cin >> minutes;
    cout << "Finally, enter the seconds of arc: ";
    int seconds;
    cin >> seconds;
    const double F = 60;
    double Degree = degrees + minutes/F + seconds/F/F;
    cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << Degree << "degrees" << endl;
    return 0 ;
}
