// sqrt.cpp -- using the sqrt() function

#include <iostream>
#include<cmath>

using namespace std;

int main()
{
    double area;
    cout << "Enter the floor area, in square feet, of your home: " <<  endl;
    cin >> area;              // input
    double side;
    side = sqrt(area);
    cout << "That's the equivalent of a square"<< side
     <<  " feet to side." << endl;
     cout << "How fascinating!" << endl;
    return 0;
}
