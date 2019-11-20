//brass.cpp -- bank account class methods
#include <iostream>
#include <cstring>
#include "brass.h"
using namespace std;

//Brass methods
Brass::Brass(const char *s, long an, double bal)
{
    std::strncpy(fullName, s, MAX - 1);
    fullName[MAX - 1] = '\0';
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt < 0)
        cout << "Negative deposit not allowed; "
        << "deposit is canceled.\n";
    else
        balance += amt;
}

void Brass::Withdraw(double amt)
{
    if (amt < 0)
        cout << "Withdrawal amount must be positive; "
        << "withdrawal canceled.\n";
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "Withdrawal amount of $ " << amt
        << " exceeds your balance.\n" << "Withdrawal canceled.\n";

}

double Brass::Balance()const
{
    return balance;
}

void Brass::ViewAcc()const
{
    //set up ###.##format
    ios_base::fmtflags initialState = cout.setf(ios_base::showpoint);
    cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    cout.setf(initialState);         //remove origin format
}

//BrassPlus methods
BrassPlus::BrassPlus(const char *s, long an, double bal,
                     double ml, double r): Brass(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) :Brass(ba) //使用隐式复制构造函数
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

//重定义 ViewAcct()
void BrassPlus::ViewAcc()const
{
    //set up ###.## format
    ios_base::fmtflags initialState = cout.setf(ios_base::fixed,ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);

    Brass::ViewAcc();  //display base portion
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout << "Loan Rate: " << 100 * rate << "%\n";
    cout.setf(initialState);

}

//重定义 Withdraw
void BrassPlus::Withdraw(double amt)
{
    //set up ###.## format
    ios_base::fmtflags initialState = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);

    double bal = Balance();
    if (amt <= bal)
        Brass::Withdraw(amt);
    else if(amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge:$" << advance *rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);

    }
    else
        cout << "Credit limit exceeded. Translation canceled.\n";
    cout.setf(initialState);
}
