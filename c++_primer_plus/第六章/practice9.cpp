//practice9.cpp -- practice6
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;
const int SIZE = 60;
const double stand = 10000.0;

struct patron{
    string name;
    double money;
};

int main()
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile;

//------打开文件------
    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

//------读取数据------
    int count;
    inFile >> count; //读取第一行数字
    inFile.get();//读取文件数据

    patron * peoplelist = new patron[count];
    for(int i = 0; i < count  ;i++)
    {
        getline(inFile, peoplelist[i].name);

        inFile >> peoplelist[i].money;
        inFile.get();

    }


//------输出数据------
    cout << "\nGrand Patrons: " << endl;
    int n = 0;
    for(int i = 0; i < count ;i++)
    {
        if(peoplelist[i].money > stand)
        {
            cout << "Patrons name: " << peoplelist[i].name << endl;
            cout << "donation: " << peoplelist[i].money << endl;
            n++;
        }
    }
    if(n == 0)
        cout << "none";

    int m = 0;
    cout << "\nPatrons: " << endl;
    for(int i = 0; i < count ;i++)
    {
        if(peoplelist[i].money <= stand)
        {
            cout << "Patrons name: " << peoplelist[i].name << endl;
            cout << "donation: " << peoplelist[i].money << endl;
            m++;
        }
    }
    if(m == 0)
        cout << "none";

//----释放内存，关闭文件----
    delete peoplelist;
    inFile.close();
    return 0;
}
