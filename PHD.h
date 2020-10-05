#pragma once
#include "Student.h"
#include <vector>

class PHD : public Student
{
private:
	int resHour;

public:
	PHD();
	bool milga();
	void print();
	PHD(int id, string fname, string lname, int courses, int resHour);
	int GetResHour() { return resHour; }
	void SetResHour(int x) { resHour = x; }
	string studType(){ return "PHD"; }
};
