#pragma once
#include "BA.h"

class MA : public BA
{
private:
	bool mehkar;

public:
	MA();
	bool milga();
	MA(int id, string fname, string lname, int courses, int *grades, bool rec);
	void print();
	string studType(){ return "MA"; }
	void setMehkar(bool _meh) { mehkar = _meh; }
	bool getMehkar() {return mehkar;}
};
