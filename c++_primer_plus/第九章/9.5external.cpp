//extern.cpp -- external  variables
#include <iostream>

using namespace std;

double warming = 0.3;

void update(double dt);
void local();

int main()
{
    cout << "Global warming id " << warming << " degree,\n";
    update(0.1);
    cout << "Global warming id " << warming << " degree.\n";
    local();
    cout << "Global warming id " << warming << " degree.\n";
    return 0;

}

void update(double dt)
{
    extern double warming;
    warming += dt;
    cout << "Updating global warming to " << warming;
    cout << " degree.\n";

}

void local ()
{
    double warming = 0.8;

    cout << "Local warming = " << warming << " degree.\n";
    cout << "But glocal warming = " << ::warming;
    cout << " degree.\n";
}
