//practice3.cpp -- 输入字符串转化为大写字母，直到输入q
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;
void Up(string &);

int main()
{
    string ch;
    cout << "Enter a string(q to quit) : \n";

    while(getline(cin,ch) && ch != "q")
    {
        Up(ch);
        cout << ch << endl;
        cout << "Next string (q to quit):";

    }
    cout << "Done!" << endl;
    system("pause");
    return 0;
}

void Up(string &ch)
{
    int strsize = ch.size();
    for (int i =0; i < strsize; i++)
    {
        if(isalpha(ch[i]))
            ch[i] =toupper(ch[i]);

    }
}
