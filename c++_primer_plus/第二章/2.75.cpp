//2.71.cpp -- ����ת��Ϊ���ĵ�λ
#include<iostream>

using namespace std;
int Light(double);

int main()
{
    cout << "Enter the number of light year: " << endl;
    double light;
    cin >> light;
    double astr = Light(light);
    cout << light << " light year = " << astr << " astronomical units." << endl;
    return 0;
}
int Light(double light)
{
    return light*63240;
}
