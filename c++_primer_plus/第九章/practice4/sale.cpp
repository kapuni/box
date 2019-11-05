//sales.cpp
#include "sales.h"

namespace SALES
{
    using std::cout;
    using std::cin;

    void setSales(Sales &s, const double ar[], int n)
    {
    //计算和存储数组
        double a, b, c;
        a = b = ar[0];
        c = 0.0;
        for(int i = 0; i < n; i++)
        {
            s.sales[i] = ar[i];
            c += ar[i];
            if(ar[i] < a)
                a = ar[i];
            if(ar[i] > b)
                b = ar[i];
        }
        s.average = c / n;
        s.max = b;
        s.min = a;
    }

    void setSales(Sales &s)
    {
    //输入数组
        double ar[QUARTERS];
        cout << "Enter 4 numbers: " << std::endl;
        for(int i = 0; i < QUARTERS; i++)
        {
            cin >> ar[i];
        }

    //计算和存储数组
        double a, b, c;
        a = b = ar[0];
        c = 0.0;
        for(int i = 0; i < QUARTERS; i++)
        {
            s.sales[i] = ar[i];
            c += ar[i];
            if(ar[i] < a)
                a = ar[i];
            if(ar[i] > b)
                b = ar[i];
        }
        s.average = c / QUARTERS;
        s.max = b;
        s.min = a;
    }

    void showSales(const Sales &s)
    {
    //显示结构数据
        for(int i = 0; i < QUARTERS; i++)
            cout << s.sales[i] << " ";
        cout << "\nThe average is: "<< s.average << "  The max is: "
             << s.max << "  The min is: " << s.min << std::endl;
    }
}
