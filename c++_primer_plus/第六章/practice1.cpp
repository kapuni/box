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
        if(isdigit(ch));//�Ƿ���ֵ

        else if(isalpha(ch))//�Ƿ���ĸ
        {
            if(isupper(ch))//�Ƿ��д
            {
                ch = tolower(ch);//ת��Сд
                cout << ch;
            }
            else{
                ch = toupper(ch);//ת����д
                cout << ch;
            }
        }
        else
            cout << ch;

        cin.get(ch);//ע��ȥ������Ļ��з�
    }

    cout << "Done!" <<endl;
    return 0;
}
