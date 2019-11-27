
#include <iostream>
#include <string>
#include "person.h"
using std::string;
using std::cout ;
using std::cin;
using std::endl;

//person  base class
Person::~Person(){}

void Person::Data()const
{
    cout << "First name: " << firstname << endl;
    cout << "Last name: " << lastname << endl;
}

void Person::Get()
{
    cout << "Enter person's firstname: ";
    getline(cin,firstname);
    cout << "Enter person's lastname:";
    getline(cin, lastname);



}

//Gunslinger class

void Gunslinger::Data()const
{
    cout << "The time:" << time << endl;
    cout << "The number of scotch:" << num << endl;
}

void Gunslinger::Get()
{
    cout << "Enter gunslinger's time:";
    cin >> time;
    cout << "Enter gunslinger's number of scotch:";
}

void Gunslinger::Set()
{
    Person::Get();
    Get();
    cout << endl;
}

void Gunslinger::Show()const
{
    cout << "Category:Gunslinger\n";
    Person::Data();
    Data();
}

//PokerPlayer class
void PokerPlayer::Data()const
{
    cout << "The card number:" << card << endl;
}

void PokerPlayer::Get()
{
    cout << "Enter Pokerplayer's card:";
    cin >> card;
    while(cin.get() != '\n')
        continue;
}

void PokerPlayer::Set()
{
    Person::Get();
    Get();
    cout << endl;
}

void PokerPlayer::Show()const
{
    cout << "Gategory:Pokerplayer\n";
    Person::Data();
    Data();
}

//BadDude class
void BadDude::Data()const
{
    Gunslinger::Data();
    PokerPlayer::Data();
}

void BadDude::Get()
{
    Gunslinger::Get();
    PokerPlayer::Get();
}

void BadDude::Set()
{
    Person::Get();
    Get();
    cout<< endl;
}

void BadDude::Show()const
{
    Person::Data();
    Data();
}
