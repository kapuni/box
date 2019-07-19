#include <iostream>

using namespace std;
int main()
{
    string phrase = "Giraffe Academy";
    string phrasesub;
    phrasesub = phrase.substr(8,3);
    cout << phrase.length() << endl;
    cout << phrase[2] << endl;
    cout << phrase.find("ffe",0) << endl;
    cout << phrasesub << endl;


    return 0;
}
