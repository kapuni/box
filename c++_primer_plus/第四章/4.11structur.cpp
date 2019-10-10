//structur.cpp -- a simple structure
#include <iostream>
struct inflatable //定义结构inflata，里面包含不同变量，类似字典
{
    char name[20];
    float volumn;
    double price;
};

int main()
{
    using namespace std;
    inflatable guest =
    {
        "Glorious Gloria",
        1.88,
        29.99
    };

    inflatable pal =
    {
        "Audacious Arthur",
        3.12,
        32.99
    };

    cout << "Expand your guest list with " << guest.name;
    cout << " and " << pal.name << "!\n";

    cout << "You can have both for $";
    cout << guest.price + pal.price << "!\n";
    return 0;
}
