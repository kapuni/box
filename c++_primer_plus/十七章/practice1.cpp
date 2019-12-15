//计算输入流中第一个$之前的字符数目
#include <iostream>
#include <string>

#include "string.h"

/*
const int LIM = 255;
int main()
{
    char input[LIM];
    char t;
    int count = 0;
    std::cout << "Enter a phase: \n";
    std::cin.get(input, LIM, '$');
    count = strlen(input);
    std::cout << count << " char .\n";
    std::cin.get(t);
    std::cout << "Next character is " << t << "\n";
    return 0;
}
*/

//string
using namespace std;
int main()
{
    string str;
    cout << "Enter a phase:" << endl;
    getline(cin, str);
    int count  = str.find('$');
    for (unsigned int i = 0; i< str.size(); i++)
    {
        if(str.at(i) != '$')
            cout << str.at(i);
    }
    cout << endl << "Number: " << count << endl;
    return 0;
}
