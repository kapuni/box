//practice3.cpp -- ¼ÆËãÀûÈó
#include <iostream>
int main()
{
    using namespace std;
    double a,b,sum;
    sum = 100.0;
    int i;
    a = b = sum;
    for(i=1;b <= a;i++)
    {
        a += 100.0*0.1;
        b += b*0.05;
    }
    cout << "The " << i << "years, Cleo's money more than Daphne\n";
    cout << "Daphne have " <<a << " dollars.\n";
    cout << "Cleo have " <<b << " dollars.\n";
    return 0;
}
