//2.71.cpp -- 使用3个用户定义函数输出
#include<iostream>

using namespace std;
void mice();
void run();

int main()
{
    mice();
    mice();
    run();
    run();
    return 0;
}

void mice()
{
    cout << "Three blind mice." << endl;
}
void run()
{
    cout << "See hoe they run." << endl;
}
