//usetime3.cpp - using the four draft of Time class
//compile usetime3.cpp and mytime0.cpp together
#include <iostream>
#include "mytime3.h"


int main()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);
    Time tosca(2, 48);
    Time total;
    Time temp;

    cout << "Aida and Tocal:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17:" << temp << endl;
    cout << "10 * Aida : " << 10* aida << endl;

    return 0;
}
