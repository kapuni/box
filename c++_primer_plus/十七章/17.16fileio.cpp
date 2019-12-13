//fileio.cpp -- saving to a file
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;
    string filename;

    cout << "Enter name for new file: ";
    cin >> filename;

    //create output stream object for new file and call it fout
    ofstream fout (filename.c_str());

    fout << "For your eyes only !\n";  //д���ļ�
    cout << "Enter your secret number: " ; //д����Ļ
    float secret;
    cin >> secret;
    fout << "Your secret number is " << secret << endl;
    fout.close();

    //����һ�������������ļ�
    ifstream fin(filename.c_str());
    cout << "Here are the contents of " << filename << ":\n";
    char ch;
    while (fin.get(ch))   //���ļ����ַ���������Ļ
        cout << ch;
    cout << "Done.\n";
    fin.close();
    return 0;

}
