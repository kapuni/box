//practice5.cpp -- s����������̺�ʹ��������������ÿһ�ٹ��������
#include<iostream>
using namespace std;
int main()
{
    cout << "Enter your driving distance: ";
    int distance;
    cin >> distance;
    cout << "Enter your amount of gasoline: ";
    int amount;
    cin >> amount;
    double b = distance / 100.00;
    double a = amount/b;
    cout << "Your fuel consumption is " << a << " (100KM/L)" << endl;
    return 0;
}
