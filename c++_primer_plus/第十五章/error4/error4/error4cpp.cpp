//error4.cpp -- using exception classes
#include <iostream>
#include<cmath>
#include "exc_mean.h"
//function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	using std::endl;
	using std::cout;
	using std::cin;

	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			cout << "Gemetric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
			cout << "Enter next set of numbers <q tp quit>: ";
		}
		catch (bad_hmean & bg)
		{
			bg.mesg();
			cout << "Try again .\n";
			continue;
		}
		catch (bad_gmean & bg)
		{
			cout << bg.mesg();
			cout << "Values used: " << bg.v1 << ", " << bg.v2 << endl;
			cout << "Sorry, you don't get to play any more.\n";
			break;
		}
		
	}
	cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0*a*b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b<0)
		throw bad_gmean(a, b);
	return std::sqrt(a*b);
}