#include <iostream>

using namespace std;

double cube(double num)
{
    return num * num *num;
    /*
    double result = num * num * num;
    return result;
    */

}

int main()
{
    /*
    double answer = cube(5.0);
    cout << answer;
    */
    cout << cube(5.0);
    return 0;
}
