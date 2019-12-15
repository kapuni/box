#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

const int LIMIT = 50;
void ShowStr(const std::string & str);
void GetStrs(std::ifstream &fin, std::vector<std::string> &v);

class Store
{
private:
    char *pd;
    std::ofstream *fout;
public:
    Store(std::ofstream &out) :fout(&out) {
        pd = new char [LIMIT];
    }
    Store(const Store &s) {
        if(this == &s)
            delete []pd;
        pd = new char[LIMIT];
        for (int i = 0; i< strlen(s.pd); i++)
            pd[i] = s.pd[i];
        fout = s.fout;
    }
    bool operator()(const std::string & str);
    char * data(const std::string & str);
    ~Store(){
        delete[] pd;
    }
};

int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    //acquire strings
    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    //store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
//    Store s = Store(fout);
//    s(vostr.at(0));
    fout.close();

    //recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open the file for input.\n";
        exit(EXIT_FAILURE);
    }

    GetStrs(fin, vistr);

    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}

void ShowStr(const std::string & str)
{
    std::cout << str << std::endl;
}

bool Store::operator() (const std::string & str)
{
    unsigned long len = str.length();
    if (fout -> is_open())
    {
        fout->write((char *)&len, sizeof(unsigned long));
        //fout -> write("\n",1);
        fout ->write(data(str), len);
        return true;
    }
    else
    {
        exit(EXIT_FAILURE);
        return false;
    }
}

char * Store::data(const std::string & str)
{
    for(int i = 0;i<str.length(); i++)
    {
        pd[i] = str[i];
    }
    return pd;
}

void GetStrs(std::ifstream & fin, std::vector<std::string> & v)
{
    unsigned long len;
    while(fin.read((char *)&len, sizeof(unsigned long)))
    {
        char * p_temp = new char[len];
        fin.read(p_temp,len);
        v.push_back(p_temp);
        delete [] p_temp;
    }

}
