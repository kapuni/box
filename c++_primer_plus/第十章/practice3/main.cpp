#include <iostream>
#include "golf1.h"
//Ö÷³ÌÐò
int main()
{
    Golf g("Alex Tony", 10);
    g.showgolf();
    std::cout << std::endl;
    g.setgolf();
    std::cout << std::endl;
    g.showgolf();
    std::cout << std::endl;
    g.sethandicap(99);
    g.showgolf();
    return 0;
}
