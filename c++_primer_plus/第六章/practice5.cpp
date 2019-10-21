//practice5.cpp -- 计算收入所得税
#include <iostream>
#include<cctype>
using namespace std;

int main()
{
    cout << "Enter your income: \n";
    int income;
    double a1, a2, a3;

    cin >> income ;
    a1 = (income-5000)*0.1;
    a2 = (income-15000)*0.15+10000*0.1;
    a3 = (income-35000)*0.2+20000*0.15+10000*0.1;
    while ( income > 0 )
    {
        if (income < 5000)
            cout << "You don't need pay for.\n";
        else if(income <15000)
            cout << "You need pay " << a1 << "for your tax.\n";
        else if (income < 35000)
            cout << "You need pay " << a2 << "for your tax.\n";
        else
            cout << "You need pay " << a3 << "for your tax.\n";
    };

    return 0;
}
