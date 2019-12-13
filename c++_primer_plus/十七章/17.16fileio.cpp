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

    fout << "For your eyes only !\n";  //写入文件
    cout << "Enter your secret number: " ; //写入屏幕
    float secret;
    cin >> secret;
    fout << "Your secret number is " << secret << endl;
    fout.close();

    //创建一个输入流的新文件
    ifstream fin(filename.c_str());
    cout << "Here are the contents of " << filename << ":\n";
    char ch;
    while (fin.get(ch))   //从文件读字符并输入屏幕
        cout << ch;
    cout << "Done.\n";
    fin.close();
    return 0;

}
