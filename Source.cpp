#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include<cstring>
#include"MA.h"
#include"PHD.h"
using namespace std;

enum option {
	stop,	//	���� �������
	addNewStudent,	//	����� ������ ���
	milgaList,	//	����� ���� �� �������� ������ �����
	mostResearch,	//	����� �� (����� �����) �� ������� ����� ��� ���� ���� �����
	countMilgaBA,	//	����� ���� ��������� ����� ����� ������ �����
	noResearchMA,	//	����� ���� (����� �����) �� ��������� MA ����� ������ �����
	overheadStudent,	//	����� ����� ������, ��� ���� ������ ����� ���� �- 15 ������
	removePHDFailers,	//	����� �� ��������� ����� ����� ����� ������ ��� ����
};

void add(vector<Student*> &vec)
{
	int *grade;
	int id, cours, numResHour, tmp;
	bool mehkarr;
	char *FirName= new char[20], *LasName=new char[20];
	Student *stu;
	cout << "enter 1 to add a BA student\n";
	cout << "enter 2 to add a MA student\n";
	cout << "enter 3 to add a PHD student\n";
	cin >> tmp;
	cout << "enter id, first name, last name and number Of Courses\n";
	cin >> id >> FirName >> LasName >> cours;
	switch (tmp)
	{
	case 1:
		cout << "enter " << cours << " grades: " << endl;
		grade = new int[cours];
		for (int i = 0; i < cours; i++)
			cin >> grade[i];
		stu = new BA (id, FirName, LasName, cours, grade);
		break;
	case 2:
		cout << "enter " << cours << " grades: " << endl;
		grade = new int[cours];
		for (int i = 0; i < cours; i++)
			cin >> grade[i];
		cout << "enter 1 if the student does research and 0 if not\n" << endl;
		cin >> mehkarr;
		stu= new MA(id, FirName, LasName, cours, grade, mehkarr);
		break;
	case 3:
		cout << "enter number of research hours\n" << endl;
		cin >> numResHour;
		stu = new PHD(id, FirName, LasName, cours, numResHour);
		break;
	default:
		cout << "ERROR" << endl;
		break;
	}
	vec.push_back(stu);
}


void milga(vector<Student*> &vec)
{
	vector<Student*>::iterator it;
	for (it = vec.begin(); it!= vec.end(); it++)
	{
		if ((*it)->milga())
			(*it)->print();
	}
}


Student* mostResearchHours(vector<Student*> &vec)
{
	int numres = 0;
	Student *stu = NULL;
	vector <Student*>::iterator its;
	for (its = vec.begin(); its != vec.end(); its++)
	{
		if ((*its)->studType() == "PHD")
			if (((PHD*)(*its))->GetResHour() > numres)
			{
				numres = ((PHD*)(*its))->GetResHour();
				stu = ((PHD*)(*its));
			}
	}
	return stu;
}

int main()
{
	//	����� �� ������ �� ����� �� ��������
	Student *s;
	vector<Student*>vec;
	string tmp;
	bool ch=false;
	int op, count=0, i=0;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != stop)
	{
		switch (op)
		{
		case addNewStudent:
			add(vec);//����� ������ ���				
			break;
		case milgaList:
			milga(vec);	//����� ���� ������ �����
			break;
		case mostResearch:
			//����� �� ������� ����� ����� ��� ���� ����:
			s = mostResearchHours(vec);
			cout << "PHD student with most research hours: ";
			cout << s->getFname() << ' ' << s->getLname() << endl;
			break;

		case countMilgaBA: 
			for_each(vec.begin(), vec.end(), [&count](Student *x) {if (x->studType() == "BA"&&x->milga()) count++; });
			cout << "#BA studnets for milga: " << count << endl;
			break;
		case noResearchMA:
			cout << "list of no research MA students : "<<endl;
			for_each(vec.begin(), vec.end(), [](Student *x) {if (x->studType() == "MA" && (!((MA*)x)->getMehkar())) cout << ((MA*)x)->getLname() << " " << ((MA*)x)->getLname() << endl; });
			//����� ����� (�� ����� �����) ��������� ����� ��� ����� ������ �����
			break;
		case overheadStudent:
			//if //(���� ����� ����� ���� � - 15 ������)
			for_each(vec.begin(), vec.end(), [&ch](Student* x) { if (x->getCourses() > 15) ch = true;
			if (ch) cout << "there is a student that takes more than 15 courses\n"; else cout << "no student takes more than 15 courses\n"; });
			break;
		case removePHDFailers:
			//����� ��������/����� �� �� ��������� ����� ����� ����� ������ ������ ����
			//����� �� ������ ���� ����� �������
			for_each(vec.begin(), vec.end(), [&vec, &i](Student*x) {if (x->studType() == "PHD" && x->getCourses() == 0)vec.erase(vec.begin(), vec.begin() + i); ++i; });
			for_each(vec.begin(), vec.end(), [](Student* x){x->print(); });
			break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	system("pause");
	return 0;
}
