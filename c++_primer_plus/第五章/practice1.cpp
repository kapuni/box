//practice.cpp -- ����a,b ��ab֮�����֮�ͣ�����ab
#include<iostream>
using namespace std;
int main()
{
    int a;
    int b;
    int i;
    int sum = 0;
    cout << "Enter number a:\n" ;
    cin >>a;
    cout << "Enter number b:\n" ;
    cin>> b;

    for (i=a; i <=b; i++)
        sum +=i;

    cout << "Sum :" << sum << endl;

    return 0;
}
