#include <iostream>

using namespace std;

int main()
{

    bool  isMale = false;
    bool isTall = false;

    if(isMale && isTall)
       {
           cout << "You are a male";
       }
    else if(isMale && !isTall){
            cout << "You are  a short male";
        }
    else if(!isMale && isTall)
        {
            cout << " You are tall but not a male";
        }
    else
        {
        cout<< " You are not a male and not tall" ;
        }

        return 0;
}
