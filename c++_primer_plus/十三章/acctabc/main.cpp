//usebrass3.cpp -- polymorphic example
//compile with acctabc.cpp
#include <iostream>
#include "acctabc.h"

const int CLIMITS = 4;
const int LEN = 40;
int main()
{
    using namespace std;
    AcctABC * p_clients[CLIMITS];

    int i;
    for(i = 0; i < CLIMITS; i++)
    {
        char temp[LEN];
        long tempnum;
        double tempbal;
        char kind;
        cout << "Enter client's name: ";
        cin.getline(temp,LEN);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or 2 for BrassPlus Account:";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2: ";
        if (kind =='1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit:$";
            cin >> tmax;
            cout << "Enter the interest rate as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp , tempnum, tempbal, tmax, trate);

        }
        while(cin.get()!='\n')
            continue;
    }
    cout << endl;
    for (i=0; i< CLIMITS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;

    }

    cout << endl;
    for (i=0; i< CLIMITS; i++)
    {
        delete p_clients[i];
    }
    cout << "Done.\n";
    return 0;
}
