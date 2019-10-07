// hexoct2.cpp -- displayvalues in hex and octal
#include <iostream>
using namespace std ;
int  main ()
{
    using namespace std;
    int cheat =42;
    int waist = 42;
    int inseam = 42;

    cout << "Monsieur cute cuts striking figure!" << endl;
    cout << "cheat = " << cheat << " (decimal)" << endl;
    cout << hex;
    cout << "waist = " << waist << " hexadecimal" << endl;
    cout << oct;
    cout << "inseam = " << inseam << " (octal)"<< endl;
    return 0;
}
