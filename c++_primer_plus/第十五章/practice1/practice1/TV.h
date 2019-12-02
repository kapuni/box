
//TV.h
#ifndef TV_H_
#define TV_H_

#include <iostream>
class Remote;
class Tv
{
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
public:
	friend class Remote;
	enum { OFF, ON };
	enum { MINVAL, MAXVAL = 20 };
	enum { ANTENNA, CABLE };
	enum { TV, DVD };

	Tv(int s = OFF, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(CABLE), input(TV) {}
	void onoff() { state ^= 1; }
	bool ison() const { return state == ON; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode ^= 1; }
	void set_input() { input ^= 1; }
	void settings() const;
	void ChangeAMode(Remote &r);
};

class Remote
{
private:
	int mode;
	int AMode;
public:
	friend class Tv;
	Remote(int m = Tv::TV, int n = NORMAL) : mode(m), AMode(n) {}
	enum { NORMAL, INTERACTIVE };
	bool volup(Tv &t) { return t.volup(); }
	bool voldown(Tv &t) { return t.voldown(); }
	void onoff(Tv &t) { t.onoff(); }
	void chanup(Tv &t) { t.chanup(); }
	void chandown(Tv &t) { t.chandown(); }
	void set_chan(Tv &t, int c) { t.channel = c; }
	void set_mode(Tv &t) { t.set_mode(); }
	void set_input(Tv &t) { t.set_input(); }
	void ShowAMode() const { std::cout << "现在是: " << (AMode == NORMAL ? "常规模式" : "交互模式") << std::endl; }
};

#endif
