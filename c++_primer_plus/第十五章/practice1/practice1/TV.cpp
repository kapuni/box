
//TV.cpp
#include "TV.h"

bool Tv::volup()
{
	if (volume < MAXVAL)
	{
		++volume;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
	if (volume > MINVAL)
	{
		--volume;
		return true;
	}
	else
		return false;
}

void Tv::chanup()
{
	if (channel < maxchannel)
		++channel;
	else
		channel = 1;
}

void Tv::chandown()
{
	if (channel > 1)
		--channel;
	else
		channel = maxchannel;
}

void Tv::settings() const
{
	std::cout << "TV is " << (state == OFF ? "OFF" : "ON") << std::endl;
	if (state == ON)
	{
		std::cout << "Volume setting = " << volume << std::endl;
		std::cout << "Channel setting = " << channel << std::endl;
		std::cout << "Mode = " << (mode == ANTENNA ? "antenna" : "cable") << std::endl;
		std::cout << "Input = " << (input == TV ? "TV" : "DVD") << std::endl;
	}
}

void Tv::ChangeAMode(Remote & r)
{
	if (state == ON)
		r.AMode ^= 1;
}