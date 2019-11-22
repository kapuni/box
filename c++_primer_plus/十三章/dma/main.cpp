//usedma.cpp -- inheritance ,friends,and DMA
//compile with dma.cpp
#include <iostream>
#include "dma.h"


int main()
{
    using namespace std;
    baseDMA shirt("Portabelly", 3);
    lacksDMA ballon ("red", "Blimpo", 4);
    hasDMA map ("Mercator", "Buffalo Keys",5 );
    cout << shirt << endl;
    cout << ballon << endl;
    lacksDMA ballon2(ballon);
    hasDMA map2;
    map2 = map;
    cout << ballon2 << endl;
    cout << map2 << endl;

    return 0;
}
