//practice3.cpp - 1.按值传递box结构  2. 传递box结构地址
#include<iostream>

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

using namespace std;
void show(box kapuni);
void show_volume(box * p_box);

int main()
{
    box kapuni;

    cout << "Enter the maker " << endl;
    cin.get(kapuni.maker, 40);
    cin.get();
    cout << "Enter the height: " << endl;
    cin >> kapuni.height;
    cout << "Enter the width: " << endl;
    cin >> kapuni.width;
    cout << "Enter the length: " << endl;
    cin >> kapuni.length;

    show_volume(&kapuni);
    show(kapuni);

    return 0;

}

void show(box kapuni)
{
    cout << "\nThe maker is: ";
	cout << kapuni.maker << endl;
	cout << "The height is: ";
	cout << kapuni.height << endl;
	cout << "The width is: ";
	cout << kapuni.width << endl;
	cout << "The length is: ";
	cout << kapuni.length << endl;
	cout << "The volume is: ";
	cout << kapuni.volume << endl;

}

void show_volume(box * p_box)
{
    p_box ->volume = p_box->height * p_box->width *p_box->length;
}
