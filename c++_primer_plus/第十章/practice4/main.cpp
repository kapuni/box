#include <iostream>
#include "sale1.h"
//������
int main()
{
    int n;
    std::cout << "Please enter the number of items:";
    std::cin >> n;//��������
    double a[n];
    std::cout << "Enter numbers: " << std::endl;
    for(int i = 0; i < n; i++)
        std::cin >> a[i];
    SALE::Sales s(a, n);
    s.showSales();
    s.setsales();
    s.showSales();

    return 0;
}
