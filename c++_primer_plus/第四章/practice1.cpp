//practice1.cpp -- input name ,grade, age, and store them (grade down one lever)
#include<iostream>
#include<string>
using namespace std;
struct who
{
    string Name;
    char Grade;
    int Age;
};
int main()
{
    string fname;
    string lname;
    string Name;
    cout << "What is your first name?\n";
    getline(cin,fname);
    cout << "What is your last name?\n" ;
    getline(cin,lname);
    cout << "What letter grade do you deserve?\n ";
    char grade;
    cin >> grade;
    cout << "What is your age ?\n";
    int age;
    cin >> age;
    who student;
    Name = fname +' ' + lname;
    int a;
    a = grade;
    a=a+1;
    grade = a;


    student.Name = Name;
    student.Grade = grade;
    student.Age = age;

    cout << "Name : " << student.Name << endl;
    cout << "Grade: " << student.Grade << endl;
    cout << "Age: " << student.Age << endl;
    return 0;

}
