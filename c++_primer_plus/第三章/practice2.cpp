//practice2.cpp -- 身高 体重的单位转换
#include<iostream>
using namespace std;
int main()
{    int feet,inch;
     cout << "Enter your height: _____feet\b\b\b\b\b\b\b";
     cin >> feet;
     cout << "                  \a_____inch\b\b\b\b\b\b\b";
     cin >> inch;
     const double M = 0.0254;
     double height = (12 * feet + inch) * M;
     cout << "Enter your weight in pounds:";
     int pounds;
     cin >> pounds;
     const double B = 2.2;
     double weight = pounds/B;
     cout << "You are " << height << " m." << endl;
     cout << "You are " << weight << "pounds." << endl;
     double IBM = weight / (height * height);
     cout << "Your IBN is " << IBM << endl;
     return 0;


}
