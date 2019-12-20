//modified 16.15 functor.cpp
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;
auto outline_lambda = [](int n) {cout << n << " "; };

int main()
{
	int vals[10] = { 50, 100, 90, 180, 60, 120, 415, 88, 188, 201 };
	list <int> yaday(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);

	cout << "Original list:\n";
	for_each(yaday.begin(), yaday.end(), outline_lambda);
	cout << endl;
	for_each(etcetera.begin(),etcetera.end(), outline_lambda);
	cout << endl;
	yaday.remove_if([](int n) {return n > 100; });// use a named function object
	etcetera.remove_if([](int n) { return n > 200; }); // construct a function object
	cout << "Trimmed lists:\n";
	for_each(yaday.begin(), yaday.end(), outline_lambda);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outline_lambda);
	cout << endl;
	return 0;
}