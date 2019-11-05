//sales.h

#include<iostream>

namespace SALES
{
    const int QUARTERS = 4;
    struct Sale
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };

    void setSales(Sales &s, const double ar[], int n);

    void setSales(Sales &s);

    void showSales(const Sales &s);
}
