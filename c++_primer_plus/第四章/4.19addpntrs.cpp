//addpntrs.cpp -- pointer addition
#include<iostream>
using namespace std;
int main()
{
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2 ,1};

    //����ָ���ַ��ʽ
    double * pw = wages;      //��ʽ�ұߵ������ʾ��wages[0]�ĵ�ַ ������һ��Ԫ�صĵ�ַ
    short * ps = &stacks[0];   // ֱ�ӽ�����ĵ�һ��Ԫ�ص�ַ��ֵ��ps

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
