//practice7.cpp -- modify 7.7
#include<iostream>

using namespace std;
const int Max = 5;

double * fill_array(double * p_begin, double  * p_end);
void show_array ( double *p_begin, double * p_end);
void revalue(double r,double * p_begin, double * p_end);

int main()
{

    double properties[Max];

    double * pt = fill_array (properties, properties + Max);
    show_array (properties, pt);

    if (properties != pt)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while(!(cin >> factor))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "Bad input : Please enter a number: ";
        }
        revalue(factor, properties, pt);
		show_array(properties, pt);

    }
    cout << "Done.\n";
    return 0;

}

double * fill_array(double * p_begin, double * p_end)
{


    int i = 1;
    double * pt;
    for (pt = p_begin; pt != p_end; pt++, i++)
	{
		cout << "Enter value #" << i << ": ";
		cin >> *pt;
//-----------输入非数字和负数的情况------------------------
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
			    continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (*pt < 0)
		    break;
	}
//-----------传递指针,注意这里传递的是地址，要用&----------
	return &(*pt);
}


void show_array(double * p_begin,double * p_end)
{

    int i = 0;
    double * pt;
    for (pt = p_begin; pt != p_end; pt++, i++)
    {
        cout << "Property # " << (i+1) << ": $";
        cout << *pt << endl;
    }
}

void revalue (double r, double * p_begin, double * p_end)
{
    for (double * pt = p_begin; pt != p_end; pt++)
        *pt *=r;
}
