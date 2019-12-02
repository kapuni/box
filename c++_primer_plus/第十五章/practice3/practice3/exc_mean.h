#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_
#include <iostream>
#include <stdexcept>
#include <string>

class bad_hmean :public std::logic_error
{
private:
	double a, b;
public:
	bad_hmean(double x = 0, double y = 0) : std::logic_error("hmean") { a = x; b = y; }
	virtual void what() {
		std::cout << "hmean(), invalid argument. a = " << a << ", b = " << b << std::endl;
	}
};


class bad_gmean : public std::logic_error
{
private:
	double a, b;
public:
	bad_gmean(double x = 0, double y = 0) : logic_error("gmean") { a = x; b = y; }
	virtual void what() { std::cout << "gmean(), auguments shouble be >= 0. a = " << a << ", b = " << b << std::endl; }
};

#endif // !EXC_MEAN_H_

