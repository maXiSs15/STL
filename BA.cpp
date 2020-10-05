#include "BA.h"
#include "Student.h"
BA::BA() {}

BA::BA(int id1, string fname1, string lname1, int courses1, int *grad)
{
	grades = grad;
	id = id1;
	fname = fname1;
	lname = lname1;
	courses = courses1;
}


bool BA::milga()
{
	if (courses >= 10)
	{
		int aver = 0;
		for (int i = 0; i < courses; i++)
			aver += grades[i];
		if (aver / courses > 95)
			return true;
	}
	return false;
}

void BA::print()
{
	this->Student::print();
	cout << "Grades:";
	for (int i = 0; i < courses; i++)
		cout << " " << grades[i];
	cout << endl;
}
