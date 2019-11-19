//Ö÷³ÌÐò£¬Í¬10-9
#include <iostream>
#include "stock3.h"

const int STKS = 4;
int main()
{
    using std::cout;
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
        };

    cout << "Stock holding:\n";
    int i;
    for (i = 0; i < STKS; i++)
        cout << stocks[i];

    const Stock * top = &stocks[0];
    for (i = 1; i < STKS; i++)
        top = &top->topval(stocks[i]);
    cout << "\nMost valuable holding:\n";
    cout << *top;
    return 0;
}

