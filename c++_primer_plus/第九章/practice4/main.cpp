//main.cpp
#include <iostream>
#include "sales.h"

int main()
{
//��������sales
    SALES::Sales s1;
    SALES::Sales s2;
//����ʽ
    int n;
    std::cout << "Please enter n items:";
    std::cin >> n;//��������
    double a[n];
    std::cout << "Enter numbers: " << std::endl;
        for(int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }
    SALES::setSales(s1, a, n);
    SALES::showSales(s1);

//�ǽ���ʽ
    std::cout << std::endl;
    SALES::setSales(s2);
    SALES::showSales(s2);

    return 0;
}
