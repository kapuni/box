//cariadic1.cpp -- using recursion to unpack a paramete pack
#include <iostream>
#include <string>
//define for 0 parameters -- terminating call
void show_list3() {}

//defination for 1 or move parameters
template<typename T, typename...Args>
void show_list3(T value, Args ... args)
{
	std::cout << value << ", ";
	show_list3(args...);
}

int main()
{
	int n = 14;
	double x = 2.1828;
	std::string mr = "Mr.String object!";
	show_list3(n, x);
	show_list3(x*x, '!', 7, mr);
	return 0;
}