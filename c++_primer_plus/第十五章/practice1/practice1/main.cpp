//main.cpp
#include <iostream>
#include "TV.h"
using namespace std;

int main()
{
	Tv s42;
	std::cout << "Initial settings for 42\" TV:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	std::cout << "\nAdjusted settings for 42\" Tv:\n";
	s42.settings();

	Remote grey;

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	std::cout << "\n42\" settings after using remote:\n";
	s42.settings();

	grey.ShowAMode();
	s42.ChangeAMode(grey);
	grey.ShowAMode();

	return 0;
}

