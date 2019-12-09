//回文测试  （有大写字母）
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool judge(const string & str);
char toLower(char ch) {return tolower(ch); }

int main()
{
    string t1;
    cout << "Please enter the string :";
    getline(cin, t1);
    int ans = judge(t1);
    if (ans > 0)
        cout << "true " << endl;
    if (ans == 0)
        cout << "false " << endl;
    return 0;
}

bool judge(const string & str)
{
    string temp;
    for (int i = 0;i<(int)str.size(); ++i)
    {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'z'))   //或if (isalpha(st[i]))
            temp.push_back(tolower(str[i]));
    }
    string s1 = temp;
    reverse(temp.begin(), temp.end());
    return temp == s1;
}
