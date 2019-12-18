//stdmove.cpp -- using std::move()
#include <iostream>
#include <utility>

//interface
class Useless
{
private:
	int n;           //number of elements
	char * pc;      //pointer to data
	static int ct;   //number of objects
	void ShowObject() const;
public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless & f);  //regular copy constructor
	Useless(Useless && f);   //move constructor
	~Useless();
	Useless operator+(const Useless & f) const;
	Useless & operator=(const Useless & f);   //copy assignment
	Useless & operator=(Useless && f);        //move assignment
	void ShowData() const;
}; 

//impelementation
int Useless::ct = 0;

Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
	
}

Useless::~Useless()
{
	
	delete[] pc;
}

Useless::Useless(int k) : n(k)
{
	++ct;
	pc = new char[n];
}

Useless::Useless(int k, char ch) :n(k)
{
	++ct;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = ch;
}

Useless::Useless(const Useless & f) : n(f.n)
{
	++ct;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
}

Useless::Useless(Useless && f) :n(f.n)
{
	++ct;
	pc = f.pc;        //steal address
	f.pc = nullptr;    //give old obkect nothing in return
	f.n = 0;
}

Useless Useless::operator+(const Useless & f)const
{
	Useless temp = Useless(n + f.n);
	for (int i = 0; i < n; i++)
		temp.pc[i] = pc[i];
	for (int i = n; i < temp.n; i++)
		temp.pc[i] = f.pc[i - n];
	return temp;
}

Useless & Useless::operator=(const Useless & f) //copy assignment
{
	std::cout << "copy assignment operator called: \n";
	if (this == &f)
		return *this;
	delete[] pc;
	n = f.n;
	pc = new char[n];
	for (int i = 0; i < n; i++)
	{
		pc[i] = f.pc[i];
	}
	return *this;
}

Useless & Useless::operator=( Useless && f) //move assignment
{
	std::cout << "move assignment operator called: \n";
	if (this == &f)
		return *this;
	delete[] pc;
	n = f.n;
	pc = f.pc;
	f.n = 0;
	f.pc = nullptr;
	return *this;
}
void Useless::ShowObject() const
{
	std::cout << "Number of elements: " << n;
	std::cout << " Data address : " << (void *)pc << std::endl;

}

void Useless::ShowData() const
{
	if (n == 0)
		std::cout << "(object empty)";
	else
	{
		for (int i = 0; i < n; i++)
			std::cout << pc[i];
	}
	std::cout << std::endl;
}

//application
int main()
{
	using std::cout;
	{
		Useless one(10, 'x');
		Useless two = one +one;  //calls move constructor
		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();
		Useless three, four;
		cout << "object three=one:\n ";
		three = one;                       //automatic copy assignment
		cout << "now object three = ";
		three.ShowData();
		cout << "now object one = ";
		one.ShowData();
		cout << "four = one + two\n";
		four = one + two;                //automatic move assignment
		cout << "now object four= ";
		four.ShowData();
		cout << "four = move(one)\n";
		four = std::move(one);              //forced move assifnment
		cout << "now object four = ";
		four.ShowData();
		cout << "and object one = ";
		one.ShowData();

	}
}