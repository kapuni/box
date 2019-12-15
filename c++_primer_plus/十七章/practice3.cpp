#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main()
{
	using namespace std;
	string filename_in, filename_out;
	char ch;
	cout << "Enter the file name to read: ";
	cin >> filename_in;

	cout << "Enter name for new file: ";
	cin >> filename_out;
	cin.get();

	ifstream fin(filename_in.c_str());
	ofstream fout(filename_out.c_str());
	if(fin.is_open())
	{
		if(fout.is_open())
		{
			while(fin.get(ch))
				fout << ch;
		}
		else
		{
			cout << "Can't open the file" << filename_out << " !\n";
	    	exit(EXIT_FAILURE);
		}
	}
	else
	{
		cout << "Can't open the file " << filename_in << " !\n";
	    exit(EXIT_FAILURE);
	}
	fin.close();
	fout.close();
	return 0;
}
