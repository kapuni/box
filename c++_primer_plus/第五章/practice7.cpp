//practice7.cpp -- 计算输入的单词个数
#include<iostream>
#include<cstring>
int main()
{
    using namespace std;
    const int Num = 50;
    char words[Num];
    int count = 0;

    cout  << "Enter wordss (to stop, type the word done):\n";


    while(cin >> words && strcmp("done",words))
        ++count;
    cout << "You entered a total of "<< count << "words.\n";
    return 0;
}
