//showpt.cpp -- setting the precision ,showing trailing pointer
#include <iostream>

int main()
{
    using std::cout;
    using std::ios_base;

    float price1 = 20.40;
    float price2 = 1.9 + 8.0 /9.0;

    cout.setf(ios_base::showpoint);  // ��ӡĩβ0��С����

    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery fiends\�� is $" << price2 << "!\n";

    cout.precision(2);
    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery fiends\�� is $" << price2 << "!\n";

    return 0;
}

