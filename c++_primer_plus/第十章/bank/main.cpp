#include <iostream>
#include <string>
#include "bank.h"



int main()
{
    using std::cout;
    cout << "Bank account information:\n" ;
    BankAccount b1("Nano Smart", "ASD",13554564);
    b1.show();
    BankAccount b2("Anny kapuni", "zcv", 351654656);
    b2.show();

    cout << "\nAfter a month:\n";
    b1.save(6546.45);
    b1.show();
    b1.withdraw(13233);
    b1.show();
    b2.withdraw(4544);
    b2.show();
    b2.save(65464.456);
    b2.show();
    return 0;
}
