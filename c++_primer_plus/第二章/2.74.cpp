//2.71.cpp -- ���϶�ת��Ϊ�����¶�
#include<iostream>

using namespace std;
int C2F(int);

int main()
{
    cout << "Please enter a Celsius value: " << endl;
    int C;
    cin >> C;
    int F = C2F(C);
    cout << C << " degree Celsius is " << F << " degrees Fahrenheit." << endl;
    return 0;
}
int C2F(int C)
{
    return 1.8*C + 32.0;
}
