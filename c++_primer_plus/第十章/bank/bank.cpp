#include <iostream>
#include <string>
#include "bank.h"

BankAccount::BankAccount(const std::string & client, const std::string & ps,double cash)
{
    fullname = client;
    account = ps;
    money = cash;
}

void BankAccount::withdraw(double cash)
{
    if(cash < 0)
        std::cout << "Number of cash can't be negative.\n";
    else if (cash > money)
        std::cout<< "You can't get more than you have.\n";
    else
        money -= cash;
}

void BankAccount::save(double cash)
{
    if(cash < 0)
    {
        std::cout << "Number of cash can't be negative.\n";

    }
    else
        money +=cash;
}

void BankAccount::show() const
{
    using std::cout;
    using std::endl;

    cout << "Fullname :" << fullname << " Account" << account << endl;
    cout << " money:$ " << money << endl;

}
