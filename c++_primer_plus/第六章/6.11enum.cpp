//enum.cpp -- using enum
#include <iostream>
//creat named constants for 0-6
enum {red, orange, yellow, green, blue, violet, indigo};

int main()
{
    using namespace std;
    cout << "Enter color code (0-6): ";
    int code;
    cin >> code ;
    while(code >= red && code <= indigo)
    {
        switch (code)
        {
            case red: cout<< "Her lios were red.\n";break;
            case orange: cout << "Her hair was orange.\n"; break;
            case yellow: cout << "Her shoes was yellow.\n"; break;
            case green: cout << "Her nails was green.\n"; break;
            case blue: cout << "Her hair was blue.\n"; break;
            case violet: cout << "Her eyes was violet.\n"; break;
            case indigo: cout << "Her mood was indigo.\n"; break;
        }
        cout << "Enter color code(0-6):";
        cin >> code;
    }
    cout << "Bye\n";
    return 0;
}
