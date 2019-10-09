#include<iostream>
using namespace std;
int main()
{
    cout << "Enter your height (inch):________\b\b\b\b\b";
    int height;
    cin >> height;
    const int a = 12;
    cout << "\aYear, you are " << height / a << " feet" << endl;
    return 0;

}
