//funtemp.cpp -- using a function template
#include <iostream>

template<class Any>  //or typename Any
void Swap(Any &a, Any & b);

int main()
{
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "i, j = " << i << " , " << j <<endl;
    cout << "Using  compiler-generated int swapper: \n";
    Swap(i,j);
    cout << "Now i, j = " << i << ", " << j << ".\n";

    double x = 24.5;
    double y = 81.7;
    cout << "x, y = " << x << " , " << y <<endl;
    cout << "Using  compiler-generated int swapper: \n";
    Swap(i,j);
    cout << "Now x, y = " << x << ", " << y << ".\n";

    return 0;
}

template<class Any>
void Swap(Any &a , Any & b)
{
    Any temp;
    temp = a;
    a=b;
    b = temp;

}
