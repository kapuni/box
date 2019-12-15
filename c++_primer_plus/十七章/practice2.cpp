#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main ()
{
    using namespace std;
    string filename;
    char ch;
    cout << "Enter name for new file: ";
    cin >> filename;
    cin.get();

    ofstream fout(filename.c_str());
    if (fout.is_open())
    {
        cout << "Enter the file content:\n";
        while (cin.get(ch) && ch!= EOF)  //ctrl + Z Ä£ÄâÎÄ¼þÎ²
            fout <<ch;
    }
    else
    {
        cout << "Can't open this file";
        exit(EXIT_FAILURE);
    }
    fout.close();
    return 0;
}
