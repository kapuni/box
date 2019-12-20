//参考程序18.10 variadic2.cpp 
#include <iostream>
using namespace std;
//0个 1个 多个
long double sum_value()
{
	return 0;
}

template<typename T>
long double sum_value(const T &t)
{
	return t;
}

template<typename T, typename... Args>
long double sum_value(const T &t, const Args&... args)
{
	return t + sum_value(args...);
}

int main()
{
	int n = 14;
	double x = 2.71828;
	char ch = 'y';
	cout << sum_value(n, x) << endl;
	cout << sum_value(x*x, ch, 'z', 8);
	return 0;
}
