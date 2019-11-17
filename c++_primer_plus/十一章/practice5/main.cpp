// stone.cpp -- user-defined conversions
// compile with stonewt.cpp


#include <iostream>
#include <cstdlib>
#include "stonewt.h"
using namespace std;

int main()
{
    Stonewt s[3];
    Stonewt s1(275);
    Stonewt s2(285.7);
    Stonewt s3(21, 8);
    s[0] = s1;
    s[1] = s2;
    s[2] = s3;
    int state;
    for (int i = 0; i < 3; i++)
    {
        cout << "#" << i + 1 << ": \n";
        cout << "Choose your style to display( \'1\' for stones, \'2\' for integer pounds, \'3\' for float pounds, others to quit): ";
        cin >> state;
        if (state != 1 && state != 2 && state != 3)
        {
            cout << "Warning: style can't satisfied!" << endl;
            cout << "Bye!\n";
            system("pause");
            return 0;
        }
        s[i].setstate(state);
        cout << "s" << i + 1 << ": " << s[i] << endl;
    }

    int st;
    cout << "Choose your style to display the result( \'1\' for stones, \'2\' for integer pounds, \'3\' for float pounds, others to quit): ";
    cin >> st;
    Stonewt sum;
    sum = s1 + s2;
    sum.setstate(st);
    cout << "s1 + s2 = " << sum << endl;
    Stonewt diff;
    diff = s3 - s2;
    diff.setstate(st);
    cout << "s3 - s2 = " << diff << endl;
    Stonewt mult1, mult2;
    mult1 = 10 * s1;
    mult2 = s3 * 1.5;
    mult1.setstate(st);
    mult2.setstate(st);
    cout << "10 * s1 = " << mult1 << endl;
    cout << "s3 * 1.5 = " << mult2 << endl;

    system("pause");
    return 0;
}
