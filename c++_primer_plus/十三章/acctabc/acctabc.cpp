//acctabc.cpp -- bank account class methods
#include <iostream>
#include "acctabc.h"
#include <cstring>

using namespace std;

//Abstract Base class
AcctABC::AcctABC(const char *s, long an, double bal)
{
    std::strncpy(fullName, s, MAX - 1);
    fullName [MAX - 1] = '\0';
    acctNum =an;
    balance = bal;
}

void AcctABC::Deposit(double amt)    //存款大于0
{
    if (amt < 0)
        cout << "Negative deposit not allowed;  deposit is cancelled.\n";
    else
        balance += amt;
}

void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

//protected methods
ios_base::fmtflags AcctABC::SetFormat()const
{
    // set up ###.## format
    ios_base::fmtflags initialState =
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    return initialState;
}

//Brass methods
void Brass::Withdraw(double amt)
{
    if(amt < 0)
        cout << "Withdrawal amount must be  positive ; withdraw cancelled.\n";
    else if (amt <= Balance())
        AcctABC::Withdraw(amt);
    else
        cout << "Withdrawal amount of $" << amt << "exceeds your balance.\n"
        << "Withdrawal cancelled.\n";
}

void Brass::ViewAcct()const
{
    ios_base::fmtflags initialState = SetFormat();
    cout << "Brass Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << balance << endl;
    cout.setf(initialState);
}

//BrassPlus methods
BrassPlus::BrassPlus(const char*s, long an, double bal,
                     double ml, double r):AcctABC(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r) :AcctABC(ba)//使用隐性复制构造函数
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct()const
{
    ios_base::fmtflags initialState = SetFormat();

    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance:$ " << Balance() << endl;
    cout << "Maximum loan: $ " << maxLoan << endl;
    cout << "Owed to bank: $ " << owesBank << endl;
    cout << "Loan Rate: " << 100 * rate << "%\n";
    cout.setf(initialState);
}

void BrassPlus::Withdraw(double amt)
{
    ios_base::fmtflags initialState = SetFormat();

    double bal = Balance();
    if (amt <= bal)
        AcctABC::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;    //多取的钱，即超额
        owesBank += advance * (1.0 + rate);   //欠钱
        cout << "Bank advance: $" << advance << endl;  //提示超额
        cout << "Finance charge: $" << advance * rate << endl;  //提示超额的利息
        Deposit(advance);           //只有将超额的钱先存进去,下面才能取出钱,不然取出超过存款会报错
        AcctABC ::Withdraw(amt);

    }
    else
        cout << "Credit limit exceed.Transaction cancelled.\n";
    cout.setf(initialState);
}
