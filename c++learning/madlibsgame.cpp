#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string color , pluraNoun, celebrity;
    cout << "Enter a color: ";
    getline(cin, color);
    cout << "Enter a plural noun: ";
    getline(cin, pluraNoun);
    cout << "Enter a celebrity: ";
    getline(cin, celebrity);

    cout << "Roses are " << color << endl;
    cout << pluraNoun << " are blue" << endl;
    cout << "I love  " << celebrity << endl;

    return 0;
}
