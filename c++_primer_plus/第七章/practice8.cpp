//practice8.cpp -- three methods of functions
#include<iostream>
using namespace std;

const int SLEN= 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
	    continue;

	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done\n";
	return 0;
}

int getinfo(student pa[], int n)
{
    int count = 0;
    cout << "\nEnter the student information: \n";
    for (int i = 0; i< n; i++)
    {
        cout << "Student #" << i+1 << endl;
        cout << "Enter the fullname: ";
        cin.getline(pa[i].fullname, SLEN);
        cout << "Enter the hobby: ";
        cin.getline(pa[i].hobby, SLEN);
        cout << "Enter the ooplevel: ";
        cin >> pa[i].ooplevel;
        if(!cin)break;
        cin.get();
        count++;
    }
    cout << "Enter end!\n\n";
    return count;
}

void display1(student st)
{
    cout << "The fullname: " << st.fullname << endl;
    cout << "The hobby:" << st.hobby << endl;
    cout << "The ooplevel:" << st.ooplevel << endl;
    cout << endl;
}

void display2(const student * ps)
{
    cout << "The fullname: " << ps->fullname << endl;
    cout << "The hobby:" << ps->hobby << endl;
    cout << "The ooplevel:" << ps->ooplevel << endl;
    cout << endl;
}

void display3(const student pa[], int n)
{
    cout << "\nHere is the student information: " << endl;
    for (int i=0; i< n; i++)
    {
        cout << "Student #" << i+1 << ": \n";
        cout << "The fullname: " << pa[i].fullname << endl;
        cout << "The hobby:" << pa[i].hobby << endl;
        cout << "The ooplevel:" << pa[i].ooplevel << endl;
        cout << endl;
    }
}
