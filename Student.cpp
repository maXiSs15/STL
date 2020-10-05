#include "Student.h"
using namespace std;

Student::Student() {}
void Student::print()
{
	cout << "ID: " << id << "\nFirst name: " << fname << "\nLast name: " << lname << "\nNum of courses: " << courses << endl;
}

Student::Student(int ID, string F, string L, int c)
{
	id = ID;
	fname = F;
	lname = L;
	courses = c;
}

Student::Student(const Student &x)
{
	setID(x.id);
	setFname(x.fname);
	setLname(x.lname);
	setCourses(x.courses);
}
