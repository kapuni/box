//practice1.cpp -- input two numbers until one is "0".
#include<iostream>
double means(double x, double y);
using namespace std;

int main()
{
    double x,y,z;

    cout << "Enter two numbers (0 to quiz): \n";
    cin >> x;
    cin >> y;
    while (x!=0 && y!=0)
    {
        z=means(x,y);
        cout << "The Means is " << z << endl;
        cout << "Enter two numbers (0 to quiz): \n";
        cin >> x >> y;
    }

    cout << "Done!\n";
    return 0;

}

double means(double x, double y)
{
    double ans;
    ans=2.0 * x*y/(x+y);
    return ans;
}
