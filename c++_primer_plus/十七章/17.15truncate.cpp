//truncate.cpp -- using get() to truncate input line ,if necessary
#include <iostream>
const int SLEN = 10;
inline void eatline() {while (std::cin.get() != '\n') continue;}

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    char name[SLEN];
    char title[SLEN];
    cout  << "Enter your name: ";
    cin.get(name, SLEN);
    if(cin.peek() != '\n')
        cout << "We were forced to truncate your title.\n";
    eatline();    //ɾ������Ĳ��֣�����һ�п�ʼ��
    cout << " Name: " << name << "\nTitle: " << title << endl;

    return 0;
}
