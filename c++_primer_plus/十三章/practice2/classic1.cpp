#include<iostream>
#include <cstring>
#include "classic1.h"

using namespace std;

Cd::Cd(char *s1, char * s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd& d)
{
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers,d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers = new char[1];
    performers[0]= '\0';
    label = new char [1];
    label[0] = '\0';
    selections = 0;
    playtime = 0;
}

Cd::~Cd()
{
    delete [] label;
    delete [] performers;

}

void Cd::Report()const
{
    cout << "performers: " << performers <<endl;
    cout << "label: " << label <<endl;
    cout << "number of selections: " << selections << endl;
    cout << "playing time in minutes:" << playtime << endl;
    cout << endl;
}

Cd&Cd::operator=(const Cd & d)
{
    if(this == &d)
        return *this;
    delete[]label;
    delete [] performers;
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

//classic methods
Classic::Classic(char * s1, char *s2,char*s3, int n,double x) : Cd(s1, s2, n,x)
{
    name = new char[strlen(s3) + 1];
    strcpy(name, s3);
}

Classic::Classic(const Classic &d,char * c):Cd(d)
{
    name = new char[strlen(d.name) + 1];
    strcpy(name, c);
}

Classic::Classic()
{
    delete [] name;

}

//redefine report
void Classic::Report()const
{
    cout << "name :" << name << endl;
    Cd::Report();
}

Classic& Classic::operator=(const Classic & d)
{
    if (this == &d)
        return *this;
    Cd::operator=(d);
    delete[] name;
    name = new char[strlen(d.name) + 1];
    strcpy(name, d.name);
    return *this;
}
