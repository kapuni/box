//exceed.cpp--exceeding some integer  limits
#include<iostream>
#define  ZERO 0
#include <climits>

using  namespace std;
int main()
{
   short sam = SHRT_MAX ;          //-32767 ~ 32767
   unsigned short sue = sam;       // 0~ 65535

   cout << "Sam has " << sam << " dollars and Sue has " << sue;
   cout << " dollars deposited." << endl
   << "Add $1 to each account." << endl << "Now" ;
   sam =sam +1;    //32767 + 1 = -32767
   sue = sue + 1;
   cout << "Sam has "<< sam<< " dollars and Sue has " << sue;
   cout << " dollars deposited.\nPoor Sam!" << endl;
   sam= ZERO;
   sue = ZERO;
   cout << "Sam has " << sam << " dollars and Sue has " << sue;
   cout << " dollars deposited." << endl;
   cout << "Take $1 from each account." << endl << "Now" ;
   sam = sam - 1;  //0-1=-1
   sue = sue - 1;  //0-1=65535
   cout << "Sam has " << sam << " dollars and Sue has " << sue;
   cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
   return 0;
}
