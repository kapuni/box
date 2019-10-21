//practice7.cpp -- input alpha until input "q",calculate the number by fist alpha
#include<iostream>
#include<cctype>
#include<string>

using namespace std;

int main()
{
    cout << "Enter the words: \n";
    string ch;
    int x =0;
    int y =0;
    int z=0;
    cin >> ch;
    while (ch != "q")
    {
        if(isalpha(ch[0]))
        {
            switch(ch[0])
            {
            case 'a':
            case 'A':
                x++;break;
            case 'e':
            case 'E':
                x++;break;
            case 'i':
            case 'I':
                x++;break;
            case 'o':
            case 'O':
                x++;break;
            case 'u':
            case 'U':
                x++;break;
            default:
                y++;
            }
        }
        else
            z++;
        cin >> ch;
    }
    cout << x << " words beginning with vowels\n"
    << y << " words beginning with consonants\n"
    << z << " others\n";

    return 0;

}
