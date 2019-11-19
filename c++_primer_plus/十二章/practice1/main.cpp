#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "cow.h"



int main()
{
    using namespace std;
    Cow a;
    a.ShowCow();
    Cow b("Bob", "sleep", 200.34);
    b.ShowCow();
    Cow c("Clummy", "run",170.72);
    c.ShowCow();
    a = c;
    a.ShowCow();

    system("pause");

    return 0;
}
