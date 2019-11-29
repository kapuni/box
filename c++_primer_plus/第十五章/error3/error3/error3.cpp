//error3.cpp -- using an exception
#include <iostream>

double hmean(double a, double b);

int main()
{
	double x, y, z;
	std::cout << "Enter two numbers: ";
	while (std::cin>>x>>y)
	{
		try {
			z = hmean(x, y);
		}                                         //后面可以跟多个catch
		catch (const char *s)                    //捕获异常 ，异常字符串（throw后面的句子）赋值给*s
		{
			std::cout << s << std::endl;
			std::cout << "Enter a new pair of numbers:";
			continue;            //回到while执行
		}
		std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
		std::cout << "Enter next set of numbers <q to quit>: ";
	}
	std::cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw "bad hmean() arguments: a=-b not allowed";   //thorw 控制程序后退->try->catch
	return 2.0 * a*b / (a + b);
}