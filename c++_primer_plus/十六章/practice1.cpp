//
#include <iostream>
#include <string>
#include <algorithm>

using std::string;
bool judge(const string & str);

int main()
{
    using std::cout ;
    using std::endl;
    using std::cin;

    string t1;
    cout << "Please enter the string:";
    cin >> t1;
    int ans = judge(t1);
    if(ans > 0)
        cout << "true" << endl;
    if(ans == 0)
        cout << "false" << endl;
    return 0;
}

bool judge(const string & str)
{
    string temp;
    temp = str;
    reverse(temp.begin(), temp.end());
    return temp == str;
}
