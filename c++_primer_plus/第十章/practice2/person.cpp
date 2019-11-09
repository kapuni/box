#include <iostream>
#include <string>
#include <cstring>
#include "person.h"

Person::Person(const std::string & ln, const char * fn)
{
    lname = ln;
    strcpy(fname, fn);

}

void Person::Show() const
{
    std::cout << "Full Name." << std::endl;
    std::cout << fname << " " << lname << "\n";
}

void Person::FormalShow() const
{
    std::cout << "Formal Name" << std::endl;
    std::cout << lname << " " << fname << "\n";
}

