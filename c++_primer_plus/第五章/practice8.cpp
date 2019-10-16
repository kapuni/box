//practice8.cpp -- using string
#include<iostream>
#include<string>
#include<cstring>
int main()
{

    using namespace std;
    string words;
    string Done =  "done";
    int count = 0;

    cout  << "Enter wordss (to stop, type the word done):\n";


    while(Done!= words)
    {
        count ++;
        cin >>  words;
    }

    cout << "You entered a total of "<< count << "words.\n";
    return 0;
}
