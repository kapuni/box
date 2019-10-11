//addpntrs.cpp -- pointer addition
#include<iostream>
using namespace std;
int main()
{
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2 ,1};

    //两种指向地址形式
    double * pw = wages;      //等式右边的数组表示是wages[0]的地址 ，即第一个元素的地址
    short * ps = &stacks[0];   // 直接将数组的第一个元素地址赋值给ps

    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";
    pw = pw +1;  //double 8bits
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

    cout << "ps= " << ps << ", *ps = " << *ps << "\n\n";
    ps = ps + 1;
    cout << "add 1 to the ps pointer:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    cout << "access two elements with array notation\n";
    cout << "stack[0] = " << stacks[0] << ", stacks[1] = "<< stacks[1] << endl;
    cout << "access two elements with pointer notation\n";
    cout << "*stack = " << *stacks << ", *(stacks +1) = "<< *(stacks+1) << endl;

    cout << sizeof(wages) << " = size of wages array\n";
    cout << sizeof(pw) << " size of pw pointer\n";
    return 0;

}
