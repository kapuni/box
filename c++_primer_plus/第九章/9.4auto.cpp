//auto.cpp -- illustrating scope of automatic variable
#include <iostream>
void oil(int x);
int main ()
{
    using namespace std;

    int texas = 31;
    int year = 1999;
    cout << "In main(),texas =  " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "In main(), year = " << year << ", &year";
    cout << &year << endl;
    oil(texas);
    cout << "In main(), texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "In main(), year = " << year << ", &year";
    cout << &year << endl;
    return 0;
}

void oil(int x)
{
    using namespace std;
    int texas = 5;

    cout << " In oil(), tesas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << " In oil(), x= " << x << ", &x = ";
    cout << &x << endl;
    {
        int texas = 113;
        cout << "In block, texas = " << texas ;
        cout << " , &tesas = " << &texas << endl;
               cout << "In block , x = " << x << ", &x = ";
        cout << &x << endl;
    }
    cout  << "Post-block texas = " << texas;
    cout << ", &texas = " << &texas << endl;

}
