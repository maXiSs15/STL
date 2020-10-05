#pragma once
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Student
{
protected:
	int id;
	string fname;
	string lname;
	int courses;

public:
	Student();
	Student(int ID, string F, string L, int c);
	Student(const Student&x);
	virtual bool milga() = 0;
	virtual void print();
	virtual string studType() = 0;
	string getFname() { return fname; }
	string getLname() { return lname; }
	int getCourses() { return courses; }
	void setID(int x) { id = x; }
	void setFname(string x) { fname = x; }
	void setLname(string y) { lname = y; }
	void setCourses(int z) { courses = z; }

};