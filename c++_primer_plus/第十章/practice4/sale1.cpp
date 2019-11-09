#include <iostream>
#include "sale1.h"

SALE::Sales::Sales()
{
    for (int i =0; i< QUARTERS; i++)
        sales[i] = 0;
    average = 0;
    max = 0;
    min = 0;
}

SALE::Sales::Sales(const double * ar , const int n)
{
    double a, b, c;
    a= b = ar[0];
    c = 0.0;
    for (int i = 0; i< n; i++)
    {
        sales[i] = ar[i];
        c += ar[i];
        if(ar[i] < a)
            a = ar[i];
        if(ar[i] > b)
            b = ar[i];
    }
    average = c / n;
    max = b;
    min = a;
}

void SALE::Sales::setsales()
{
    double ar[QUARTERS] = {0, 0, 0, 0};
    std::cout << "Please enter 4 number: " << std::endl;
    int  n = 0;
    do{
        std::cin >> ar[n];
        n++;
    }while((n < QUARTERS));

    double a, b, c;
    a= b = ar[0];
     c = 0.0;
    for(int i = 0; i < n; i++)
    {
        sales[i] = ar[i];
        c += ar[i];
        if(ar[i] < a)
            a = ar[i];
        if(ar[i] > b)
            b = ar[i];
    }
    average = c / n;
    max = b;
    min = a;
}

void SALE::Sales::showSales() const
{
    //显示结构数据
    for(int i = 0; i < QUARTERS; i++)
        std::cout << sales[i] << " ";
    std::cout << "\nThe average is: "<< average << "  The max is: "
        << max << "  The min is: " << min << std::endl;
}
