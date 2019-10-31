//practice4.cpp -- Ð´Á½¸öshowº¯Êý
#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
struct stringy
{
	char *str;
	int ct;
};
void set(stringy&, char *);
void show(const stringy&, int n = 1);
void show(const char *, int n = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	delete[]beany.str;
	beany.str = NULL;
	system("pause");
	return 0;
}

void set(stringy& str, char *testing)
{
	str.ct = strlen(testing);
	str.str = new char[str.ct + 1];
	str.str=testing;
}

void show(const char*str, int n)
{
    for (int i=0; i<n ;i++)
        cout << str << endl;
}

void show (const stringy &str,int n)
{
    for (int i=0;i<n; i++)
        cout << str.str << endl;
}
