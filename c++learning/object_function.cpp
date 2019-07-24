#include <iostream>

using namespace std;

class Student
{
public:
    string name;
    string major;
    double gpa;
    Student(string aName ,string aMajor, double aGpa)
    {
        name = aName;
        major = aMajor;
        gpa = aGpa;
    }
    bool hashonors(){
        if(gpa >= 3.0){
            return true;
        }
        return false;
    }
};

int main()
{
    Student student1("Bob", "Math", 2.7);
    Student student2("Mike", "Art", 3.6);
    cout << student1.name << endl;
    cout << student2.hashonors();

    return 0;
}
