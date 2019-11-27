#include <iostream>
#include <string>
#include "emp.h"

using namespace std;

abstr_emp::abstr_emp()
{
	fname = "no name";
	lname = "no name";
	job = "no job";
}

abstr_emp::abstr_emp(const string & fn, const string & ln, const string & j)
{
	fname = fn;
	lname = ln;
	job = j;
}

abstr_emp::~abstr_emp() {}

void abstr_emp::ShowAll()const
{
	cout << "First name: " << fname << endl;
	cout << "Last name:" << lname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::SetAll() 
{
	cout << "Enter the first name:" << endl;
	getline(cin, fname);
	cout << "Enter the last name :" << endl;
	getline(cin, lname);
	cout << "Enter the job:" << endl;
	getline(cin, job);
	
}

std::ostream & operator<<(ostream & os, const abstr_emp & e)
{
	os << e.fname << " " << e.lname;
	return os;
}

//employee class
employee::employee(const string & fn, const string & ln,const string &j)
	:abstr_emp(fn,ln,j)
{}

void employee::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << endl;
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

//manager class
manager::manager()
{
	inchargeof = 0;
}

manager::manager(const string & fn, const string &ln, const string & j, int ico)
	:abstr_emp(fn, ln,j), inchargeof(ico)
{}

manager::manager(const abstr_emp &e,int ico)
	:abstr_emp(e) ,inchargeof(ico)
{}

manager::manager(const manager & m): abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof:" << inchargeof << endl;
	cout << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter the inchargeof" << endl;
	cin >> inchargeof;
	while (cin.get() != '\n')
	{
		continue;
	}
}

//fink class
fink::fink()
{
	reportsto = "no nane";
}

fink::fink(const string & fn,const string &ln, const string &j,const string & rpo)
	:abstr_emp(fn,ln,j), reportsto(rpo)
{}

fink::fink(const abstr_emp & e, const string & rpo)
	:abstr_emp(e), reportsto(rpo)
{}

fink::fink(const fink & f) :abstr_emp(f)
{}

void fink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "Reportsto:" << reportsto << endl;
	cout << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter the reportsto:" << endl;
	getline(cin, reportsto);
}

//highfink class
highfink::highfink()
{}

highfink::highfink(const string & fn,const string &ln, const string & j,const string  & rpo, int ico)
	:abstr_emp(fn,ln,j), fink(fn,ln,j,rpo),manager(fn,ln,j,ico)
{}

highfink::highfink(const abstr_emp & e,const string & rpo,int ico)
	:abstr_emp(e), fink(e, rpo), manager(e, ico)
{}

highfink::highfink(const manager & m,const string & rpo)
	:abstr_emp(m), fink(m, rpo), manager(m)
{}

highfink::highfink(const highfink & h) : abstr_emp(h), fink(h), manager(h)
{
}

void highfink::ShowAll() const
{
	manager::ShowAll();
	cout << "Reportsto: " << ReportsTo() << endl;
	cout << endl;
}

void highfink::SetAll()
{
	manager::SetAll();
	cout << "Enter the reportsto: " << endl;
	getline(cin, fink::ReportsTo());
}

