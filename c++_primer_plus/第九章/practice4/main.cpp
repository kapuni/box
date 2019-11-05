//main.cpp
#include <iostream>
#include "sales.h"

int main()
{
//声明两个sales
    SALES::Sales s1;
    SALES::Sales s2;
//交互式
    int n;
    std::cout << "Please enter n items:";
    std::cin >> n;//输入数据
    double a[n];
    std::cout << "Enter numbers: " << std::endl;
        for(int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }
    SALES::setSales(s1, a, n);
    SALES::showSales(s1);

//非交互式
    std::cout << std::endl;
    SALES::setSales(s2);
    SALES::showSales(s2);

    return 0;
}
