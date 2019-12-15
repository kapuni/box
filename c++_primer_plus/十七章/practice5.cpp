#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>
#include <cstdlib>

int main()
{
    using namespace std;
    //预先在两个文件中分别写入名字
    ofstream fout_Mat("mat.dat", ios_base::out);
    fout_Mat << "Kate\n" << "Rose\n" << "Mike\n";
    ofstream fout_Pat("pat.dat", ios_base::out);
    fout_Pat << "Kate\n" << "Joy\n" << "Tony\n" << "Kapuni\n";
    fout_Mat.close();
    fout_Pat.close();

    //读两个文件中的名字
    ifstream fin_Mat("mat.dat", ios_base::in);
    ifstream fin_Pat("pat.dat", ios_base::in);

    string name;
    set<string> namelist_Mat, namelist_Pat, common;
    set <string>::iterator pd;
    if(fin_Pat.is_open() && fin_Mat.is_open())
    {
        while(getline(fin_Mat, name))
            namelist_Mat.insert(name);
        cout << "\nMat's friends are :\n";
        for(pd = namelist_Mat.begin(); pd!= namelist_Mat.end(); pd++)
            cout << *pd << " ";

        while(getline(fin_Pat, name))
            namelist_Pat.insert(name);
        cout << "\nPat's friends are :\n";
        for(pd = namelist_Pat.begin(); pd!= namelist_Pat.end(); pd++)
            cout << *pd << " ";
        fin_Pat.close();
        fin_Mat.close();
    }
    else
        exit(EXIT_FAILURE);
    //合并两个文件的名字
    set_union(namelist_Mat.begin(),namelist_Mat.end(), namelist_Pat.begin(),namelist_Pat.end(),
              inserter(common,common.begin()));
    ofstream fout_union("matnpat.dat", ios_base::out);
    for(pd = common.begin(); pd != common.end(); pd++)
        fout_union << *pd << " ";
    fout_union.close();

    //读文件的名字
    ifstream fin_union("matnpat.dat", ios_base::in);
    cout << "\nfriends invited are :\n";
    while(getline(fin_union, name))
        cout << name << " ";
    cout << endl;
    fin_union.close();

    return 0;
}
