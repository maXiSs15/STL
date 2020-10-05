#include "PHD.h"
#include "Student.h"


PHD::PHD() {}

bool PHD::milga()
{
	if ((courses >= 2) && (resHour >= 25))
		return true;
	return false;
}

void PHD::print()
{
	Student::print();
	cout << "hours of recearching: " << resHour << endl;
}

PHD::PHD(int id1, string fname1, string lname1, int courses1, int reshour1)
{
	resHour = reshour1;
	id = id1;
	fname = fname1;
	lname = lname1;
	courses = courses1;
}

