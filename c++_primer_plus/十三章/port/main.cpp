#include <iostream>
#include<string>
#include "port.h"

using namespace std;

int main()
{
    Port port1("gallo", "tawny", 20);
    cout << port1 << endl << endl;
    VintagePort vp("gallo", "vintage", 24, "Old Velvet", 16);
    VintagePort vp2(vp);
    cout << vp2 << endl << endl;
    VintagePort vp3;
    vp3 = vp;
    cout << vp3 << endl << endl;

    Port * p_port;
    p_port = &port1;
    p_port ->Show();
    cout << endl;
    p_port = &vp;
    p_port ->Show();
    cout << endl;
    return 0;
}
