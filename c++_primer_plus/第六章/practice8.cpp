//practice8/cpp -- 读取文本，计算文本的字符
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;
const int Size = 60;

int main()
{
    char filename[Size];
    ifstream inFile;

    cout << "Enter name of words file: ";
    cin.getline(filename, Size);
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Programmer terminating.\n";
        exit(EXIT_FAILURE);
    }
    char words;
    int count = 0;
    inFile >> words;
    while (inFile.good())
    {
        ++count;
        inFile >> words;
    }
    if (inFile.eof())
        cout << "End of file reached.n";
    else if(inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
    if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "chars: " << count << endl;
    }
    inFile.close();
    return 0;

}
