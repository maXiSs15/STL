#pragma once
#include "Student.h"
class BA :
	public Student
{
protected:
	int *grades;
	int size;
public:
	BA();
	BA(int id, string fname1, string lname1, int courses1, int *grad);
	bool milga();
	void print();
	string studType() { return "BA"; }
};

