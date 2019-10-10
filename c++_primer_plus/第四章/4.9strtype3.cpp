// strtype3.cpp -- more string class feature
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main ()
{
    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    str1 = str2;
    strcpy(charr1, charr2);

    str1 += " paste";   //空格也算一个字符
    strcat(charr1, " juice");

    int len1 = str1.size();
    int len2 = strlen(charr1);

    cout << "The string " << str1 << " contains "
         << len1 << " characters.\n";
    cout << "The string " << charr1 << " contains " << len2 << " characters.\n";
    return 0 ;
}
