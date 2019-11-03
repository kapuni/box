//9.6twofile1.cpp -- variable with external and internal linkage
#include <iostream>

using namespace std;
int tom =3;
int dick = 30;
static int harry = 300;

void remote_access();

int main()
{
    cout << "main()reports the following address:\n" << endl;
    cout << &tom << " = &tom," << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
    remote_access();
    return 0;
}
