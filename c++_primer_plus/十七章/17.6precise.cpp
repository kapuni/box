//precise.cpp -- setting the precision
#include <iostream>
//设置精度一直有效
int main()
{
    using std::cout;

    float price1 = 20.40;
    float price2 = 1.9 + 8.0 /9.0;

    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery fiends\” is $" << price2 << "!\n";

    cout.precision(2);
    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery fiends\” is $" << price2 << "!\n";

    return 0;
}
