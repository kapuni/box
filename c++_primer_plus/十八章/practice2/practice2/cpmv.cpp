//cpmv.cpp
#include <iostream>
#include "cpmv.h"
using namespace std;

Cpmv::Cpmv()
{
	pi = new Info;
	pi->qcode = "qcode";
	pi->zcode = "zcode";
	cout << "Default constructor called.\n";
}

Cpmv::Cpmv(string q, string z)
{
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
	cout << "String constructor called.\n";

}

Cpmv::Cpmv(const Cpmv &cp)
{
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	cout << "Cpoy constructor called.\n";
}

Cpmv::Cpmv(Cpmv &&mv)
{
	pi = new Info;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "qcode";
	mv.pi->zcode = "zcode";
	cout << "None constructor called.\n";
}

Cpmv::~Cpmv()
{
	delete pi;
	cout << "Destructor called .\n";
}

Cpmv & Cpmv::operator=(const Cpmv &cp)
{
	cout << "Copy assignment operator called.\n";
	if (this == &cp)
		return *this;
	delete pi;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	return *this;
}

Cpmv &Cpmv::operator=(Cpmv &&mv)
{
	cout << "Move assignment operator called.\n";
	cout << "Copy assignment operator called.\n";
	if (this == &mv)
		return *this;
	delete pi;
	pi = new Info;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "qcode";
	mv.pi->zcode = "zcode";
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv &obj)const
{
	cout << "Plus operator called.\n";
	Cpmv sum;
	sum.pi->qcode = pi->qcode + obj.pi->qcode;
	sum.pi->zcode = pi->zcode + obj.pi->zcode;
	return sum;
}

void Cpmv::Display()const
{
	cout << "qcode :" << pi->qcode << endl;
	cout << "zcode: " << pi->zcode << endl;

}