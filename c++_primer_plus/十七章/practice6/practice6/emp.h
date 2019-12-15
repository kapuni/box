//emp.h
#ifndef EMP_H
#define EMP_H
#include <iostream>
#include <fstream>
#include <string>

enum classkind { Employee, Manager, Fink, Highfink };

using std::cout;
using std::cin;
using std::endl;

class abstr_emp
{
private:
	std::string fname;
	std::string lname;
	std::string job;
public:
	abstr_emp();
	abstr_emp(const std::string & fn, const std::string & ln, const std::string & j);
	virtual void ShowAll() const;
	virtual void WriteAll(std::ofstream &fout) const;
	virtual void GetAll(std::ifstream &fin);
	virtual void SetAll();
	friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
	//~abstr_emp(){} 
};

class employee : virtual public abstr_emp
{
public:
	employee();
	employee(const std::string & fn, const std::string & ln, const std::string & j);
	virtual void ShowAll() const;
	virtual void WriteAll(std::ofstream &fout) const;
	virtual void GetAll(std::ifstream &fin);
	virtual void SetAll();
};

class manager : virtual public abstr_emp
{
private:
	int inchargeof;
protected:
	int InChargeOf() const { return inchargeof; }
	int & InChargeOf() { return inchargeof; }
public:
	manager();
	manager(const std::string & fn, const std::string & ln, const std::string & j, int ico = 0);
	manager(const abstr_emp & e, int ico);
	manager(const manager & m);
	virtual void ShowAll() const;
	virtual void WriteAll(std::ofstream &fout) const;
	virtual void GetAll(std::ifstream &fin);
	virtual void SetAll();
};

class fink : virtual public abstr_emp
{
private:
	std::string reportsto;
protected:
	const std::string ReportsTo() const { return reportsto; }
	std::string & ReportsTo() { return reportsto; }
public:
	fink();
	fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo);
	fink(const abstr_emp & e, const std::string & rpo);
	fink(const fink & e);
	virtual void ShowAll() const;
	virtual void WriteAll(std::ofstream &fout) const;
	virtual void GetAll(std::ifstream &fin);
	virtual void SetAll();
};

class highfink : public manager, public fink
{
public:
	highfink();
	highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico);
	highfink(const fink & f, int ico);
	highfink(const manager & m, const std::string & rpo);
	highfink(const highfink & h);
	virtual void ShowAll() const;
	virtual void WriteAll(std::ofstream &fout) const;
	virtual void GetAll(std::ifstream &fin);
	virtual void SetAll();
};

void abstr_emp::ShowAll() const
{
	cout << "First name: " << fname << endl;
	cout << "Last name: " << lname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::WriteAll(std::ofstream &fout) const
{
	fout << fname << endl;
	fout << lname << endl;
	fout << job << endl;
}

void abstr_emp::GetAll(std::ifstream &fin)
{
	fin >> fname >> lname >> job;
}

void abstr_emp::SetAll()
{
	cout << "Enter first name: ";
	cin >> fname;
	cout << "Enter last name: ";
	cin >> lname;
	cout << "Enter job:";
	cin >> job;
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof is: " << inchargeof << endl;
}

void manager::WriteAll(std::ofstream &fout) const
{
	fout << Manager << endl;
	abstr_emp::WriteAll(fout);
	fout << inchargeof << endl;
}

void manager::GetAll(std::ifstream &fin)
{
	abstr_emp::GetAll(fin);
	fin >> inchargeof;
}

void manager::SetAll()
{

	abstr_emp::SetAll();
	cout << "Enter inchargeof: ";
	cin >> inchargeof;
	cin.get();
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Reportsto is: " << reportsto << endl;
}

void fink::WriteAll(std::ofstream &fout) const
{
	fout << Fink << endl;
	abstr_emp::WriteAll(fout);
	fout << reportsto << endl;
}

void fink::GetAll(std::ifstream &fin)
{
	abstr_emp::GetAll(fin);
	fin >> reportsto;
}

void fink::SetAll()
{
	abstr_emp::SetAll();

	cout << "Enter the reportsto: ";
	cin >> reportsto;
}

void highfink::ShowAll() const
{
	manager::ShowAll();
	cout << "Reportsto is: " << fink::ReportsTo() << endl;
}

void highfink::WriteAll(std::ofstream &fout) const
{
	fout << Highfink << endl;
	abstr_emp::WriteAll(fout);
	fout << manager::InChargeOf() << endl;  //不能直接调用manager::WriteAll()，会写两次枚举值 
	fout << fink::ReportsTo() << endl;
}

void highfink::GetAll(std::ifstream &fin)
{
	manager::GetAll(fin);
	fin >> fink::ReportsTo();
}

void highfink::SetAll()
{
	manager::SetAll();

	cout << "Enter the reportsto: ";
	std::string a;
	cin >> a;
	fink::ReportsTo() = a;
}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::WriteAll(std::ofstream &fout) const
{
	fout << Employee << endl;
	abstr_emp::WriteAll(fout);
}

void employee::GetAll(std::ifstream &fin)
{
	abstr_emp::GetAll(fin);
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

abstr_emp::abstr_emp() : fname("none"), lname("none"), job("none")
{
}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j) : fname(fn), lname(ln), job(j)
{
}


std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
	os << "First name: " << e.fname << endl;
	os << "Last name: " << e.lname << endl;
	os << "Job: " << e.job << endl;
	return os;
}

employee::employee() : abstr_emp()
{
}

employee::employee(const std::string & fn, const std::string & ln, const std::string & j) : abstr_emp(fn, ln, j)
{
}

manager::manager() : abstr_emp(), inchargeof(0)
{
}

manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico)
{
}

manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico)
{
}

manager::manager(const manager & m) : abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

fink::fink() : abstr_emp(), reportsto("none")
{
}

fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo) : abstr_emp(fn, ln, j), reportsto(rpo)
{
}

fink::fink(const abstr_emp & e, const std::string & rpo) : abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink & e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}

highfink::highfink() : abstr_emp(), manager(), fink()
{
}

highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j,
	const std::string & rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}

highfink::highfink(const fink & f, int ico) : abstr_emp(f), manager(f, ico), fink(f)
{
}

highfink::highfink(const manager & m, const std::string & rpo) : abstr_emp(m), manager(m), fink(m, rpo)
{
}

highfink::highfink(const highfink & h) : abstr_emp(h), manager(h), fink(h)
{
}
#endif
