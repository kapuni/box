//variadic2.cpp 
#include <iostream>
#include <string>

//defination for 0 parameters
void show_list() {}

//defination for 1 parameter
template<typename T>
void show_list(const T & value)
{
	std::cout << value << '\n';
}

//defination for 2 or more parameters
template<typename T, typename...Args>
void show_list(const T& value, const Args& ...args)
{
	std::cout << value << ", ";
	show_list(args...);

}

int main()
{
	int n = 14;
	double x = 2.71828;
	std::string mr = "Mr.string objects!";
	show_list(n, x);
	show_list(x*x, '!', 7, mr);
	return 0;
}