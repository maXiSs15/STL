#include "MA.h"
#include "Student.h"
#include"BA.h"

MA::MA() {}

bool MA::milga()
{
	if (courses >= 7)
	{
		int aver = 0;
		for (int i = 0; i < courses; i++)
			aver += grades[i];
		if (((aver / courses) > 90) && mehkar)
			return true;
	}
	return false;
}

MA::MA(int id1, string fname1, string lname1, int courses1, int *grades1, bool rec)
{
	mehkar = rec;
	grades = grades1;
	id = id1;
	fname = fname1;
	lname = lname1;
	courses = courses1;
}

void MA::print()
{
	BA::print();
	cout << "research: ";
	if (mehkar)
		cout << " yes";
	else cout << "no";
	cout << endl;
}
