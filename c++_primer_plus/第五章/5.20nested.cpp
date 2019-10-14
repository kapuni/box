//nested.cpp -- nested loops and 2-D array
#include<iostream>
const int Cities = 5;
const int Years = 4;
int main()
{
    using namespace std;
    const char * cities[Cities] =
    {
        "Gribble City",
        "Gribbletown",
        "Nanjing",
        "Hangzhou",
        "Shanghai"
    };
    int maxtemps[Years][Cities] =
    {
        {
            95,99,86,100,104 },
        {
            95,97,90,106,102},
        {
            96,100,940,107,105},
        {
            97,102,105,107,109}
    };

    cout << "Maximum temperaturas for 2002-2005\n\n";
    for(int city = 0; city < Cities; ++city)
    {
        cout << cities[city] << ": \t";
        for (int year = 0; year < Years; ++year)
            cout << maxtemps[year][city] << "\t";
        cout << endl;
    }
    return 0;
  }
