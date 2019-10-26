//practice9.cpp -- 使用calculat函数，调用2个double和一个指向函数的指针
#include<iostream>

using namespace std;
double calculate(double x, double y, double (*p)(double x, double y) );
double add (double x, double y);
double subtract (double x, double y);
double multiply (double x, double y);
double divide (double x, double y);

int main ()
{
    double x, y;
    double(*pf[4])(double x, double y);
    pf[0] = add;
    pf[1] = subtract;
    pf[2] = multiply;
    pf[3] = divide;

    cout << "Enter two numbers (q to quit): \n";
    while(cin >> x >> y)
    {
        for (int i=0;i<4; i++)
            cout << "The answer is: " << (*pf[i])(x, y) << endl;

    }
    cout << "Done!\n";
    return 0;
}

double calculate(double x, double y, double(*p)(double x, double y))
{
    return (*p)(x, y);
}

double add(double x, double y)
{
    return x + y;
}

double subtract(double x, double y)
{
    return x - y;
}

double multiply(double x, double y)
{
    return x * y;
}

double divide(double x, double y)
{
    return x / y;
}
