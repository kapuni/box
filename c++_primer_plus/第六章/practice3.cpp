//practice3.cpp -- a menu with four choices
#include<iostream>
void showmenu();
using namespace std;
int main()
{
    using namespace std;
    cout << "Please enter one of the following choices:\n"
    << "c) carnivore         p) pianist\n"
    << "t) tree              g) game\n";
    char ch;
    cin.get(ch);
    switch (ch)
    {
        case 'c': cout << "carnivore is like what.\n";
                  break;
        case 'p':
            cout << "pianist is a good choice.\n";
            break;
        case 't' :
            cout << "A maple is a tree.\n";
            break;
        case 'g' :
            cout << "Let's play a game.\n";
            break;
        default:
            cout << "Please enter c, p, g, t: \n";
    }
    return 0;

}
void showmenu()
{
    cout << "Please enter one of the following choices:\n"
    << "c) carnivore         p) pianist\n"
    << "t) tree              g) game\n";
}
