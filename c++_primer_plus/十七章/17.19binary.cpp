//binary.cpp -- binary file I/O
#include <iostream> // not required by most systems
#include <fstream>
#include <iomanip>
#include <cstdlib>  // for exit()

inline void eatline()
{
    while(std::cin.get() != '\n')
        continue;
}
struct planet
{
    char name[20];        //name of planet
    double population;    //its population
    double g;             //its acceleration
};

const char * file = "planets.dat";

int main()
{
    using namespace std;
    planet p1;
    cout << fixed << right;

    //show initial contents
    ifstream fin;
    fin.open(file, ios_base::in| ios_base::binary) ; //binary file

    if(fin.is_open())
    {
        cout << "Here are the current contents of the " << file << " file:\n";
        while(fin.read((char *)&p1,sizeof p1))
        {
            cout << setw(20) << p1.name << ": "
                << setprecision(0) << setw(12) << p1.population
                << setprecision(2) << setw(6) << p1.g << endl;
        }
        fin.close();
    }

    //add new data
    ofstream fout(file,
                  ios_base::out | ios_base::app | ios_base::binary);

    if(!fout.is_open())
    {
        cerr << "Can't open " << file << " file foe output:\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter planet name (enter a blank line to quit): \n";
    cin.get(p1.name,20);
    while (p1.name[0] != '\0')
    {
        eatline();
        cout << "Enter planetary population: ";
        cin >> p1.population;
        cout << "Enter plant's acceleration pf gravity: ";
        cin >> p1.g;
        eatline();
        fout.write((char *) &p1, sizeof p1);
        cout << "Enter planet name(enter a blank line to quit): \n";
        cin.get(p1.name, 20);
    }
    fout.close();

    //show revised file
    fin.clear();   //not required for some implementations ,but won't hurt
    fin.open(file, ios_base::in | ios_base::binary);
    if (fin.is_open())
    {
        cout << "Here are the current contents of the " << file << " file:\n";
        while(fin.read((char *)&p1,sizeof p1))
        {
            cout << setw(20) << p1.name << ": "
                << setprecision(0) << setw(12) << p1.population
                << setprecision(2) << setw(6) << p1.g << endl;
        }
        fin.close();
    }

    cout <<"Done.\n" ;
    return 0;
}

//²»ÄÜ»»³Éstring£¬
