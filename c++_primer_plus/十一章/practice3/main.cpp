// randwalk.cpp -- using the Vector class
// compile with the vector.cpp file

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int N;
    int maxsteps, minsteps, sumsteps;
    maxsteps = 0;
    minsteps = 65535;
    sumsteps = 0;
    double avesteps;
    cout << "How many times of test would you want: ";
    cin >> N;
    cout << "\nEnter target distance: ";
    cin >> target;
    cout << "Enetr step length: ";
    cin >> dstep;
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.set(dstep, direction, 'p');
            result = result + step;
            steps++;
        }
        sumsteps += steps;
        if (steps > maxsteps)
        {
            maxsteps = steps;
        }
        if (steps < minsteps)
        {
            minsteps = steps;
        }
        steps = 0;
        result.set(0.0, 0.0);
    }
    avesteps = sumsteps / N;
    cout << "Walk finished!\nAfter " << N << " times of test, the result is following:\n";
    cout << "The maxmum steps is " << maxsteps << ", the minimum steps is " << minsteps << ", and the average steps is " << avesteps << ".\n";
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;

    system("pause");
    return 0;
}
