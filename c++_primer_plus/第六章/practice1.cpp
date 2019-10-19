// practice1.cpp -- input until "@" ; recycle input except number  ; exchange alpha like "A" <--> "a"
#include<iostream>
#include<cctype>

int main()
{
    using namespace std;
    cout << "Enter text, and type @ to terminate input.\n";
    char ch;

    cin.get(ch);
    while (ch != '@')
    {
        if(isdigit(ch));//是否数值

        else if(isalpha(ch))//是否字母
        {
            if(isupper(ch))//是否大写
            {
                ch = tolower(ch);//转换小写
                cout << ch;
            }
            else{
                ch = toupper(ch);//转换大写
                cout << ch;
            }
        }
        else
            cout << ch;

        cin.get(ch);//注意去掉输入的换行符
    }

    cout << "Done!" <<endl;
    return 0;
}
