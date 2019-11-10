#include <iostream>
#include <cstring>
#include <string>
#include "plorg.h"



Plorg::Plorg(string m , int n)         //Plorg::Plorg(char * m , int n)
{
	name = m;              //strcpy(name,m); 字符数组的赋值
	CI = n;
}

void Plorg::update(const int & n)
{
	CI = n;
}

void Plorg::show() const
{
	using std::cout;
	using std::endl;
	cout << "Please show the name and CI of Plorg: " << endl;
	cout << "name: " << name << " CI: " << CI << endl;

}
