//主程序
#include <iostream>
#include <string>
#include <cstring>
#include "abc2.h"

const int BASE = 3;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    ABC * p_base[BASE];
    char temp[40];
    char tcolor[40];
    char tstyle[40];
    int tempnum;
    int kind;

    for (int i = 0; i < BASE; i++)
    {
        cout << "Enter base's label: " << endl;
        cin.getline(temp, 40);
        cout << "Enter base's rating: " << endl;
        cin >> tempnum;
        cout << "Enter 1 for base, 2 for lacksbase or 3 for hasbase: " << endl;
        while (cin >> kind && (kind != 1 && kind != 2 && kind != 3))
        {
            cout << "Enter either 1, 2 or 3: " << endl;
        }
        //混合输入数字和字符时记得注意，
        //数字输入后留换行符在输入队列中，并没去掉、
        cin.get();//去掉换行符
        if (kind == 1)
        {
            p_base[i] = new baseDMA(temp, tempnum);
        }
        else if (kind == 2)
        {

            cout << "Enter the color: " << endl;
            cin.get(tcolor, 40);
            p_base[i] = new lacksDMA(tcolor, temp, tempnum);
        }
        else if (kind == 3)
        {
            cout << "Enter the style: " << endl;
            cin.getline(tstyle, 40);
            p_base[i] = new hasDMA(tstyle, temp, tempnum);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (int i = 0; i < BASE; i++)
    {
        p_base[i]->View();
        cout << endl;
    }

    for (int i = 0; i < BASE; i++)
    {
        delete p_base[i];//释放对象
    }
    cout << "Done.\n";
    return 0;
}

