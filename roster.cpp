#include <iostream>
#include <string>
#include <array>
#include "roster.h"

using namespace std;

void Roster::parse(string studentdata)
{
    // rhs = right hand side index
	// lhs = left hand side index
	int rhs = studentdata.find(','); // get index of first comma
			string studentID = studentdata.substr(0, rhs); // read everything from idx[0] for 2(rhs) characters

	int lhs = rhs + 1; // get next index 2+1 = idx[3] aka "J"
		rhs = studentdata.find(',', lhs); // find the next comma starting at lhs(idx[3]) so rhs = 7
			string firstName = studentdata.substr(lhs, rhs - lhs); // read everyone from idx[lhs(3)] for rhs(7) - lhs(3) characters so 7-3 = 4 characters

	lhs = rhs + 1;
		rhs = studentdata.find(',', lhs);
			string lastName = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
		rhs = studentdata.find(",", lhs);
			string emailAddress = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
		rhs = studentdata.find(',', lhs);
			int age = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
		rhs = studentdata.find(",", lhs);
			int daysInCourse1 = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
		rhs = studentdata.find(",", lhs);
			int daysInCourse2 = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
		rhs = studentdata.find(",", lhs);
			int daysInCourse3 = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
		rhs = studentdata.find(",", lhs);
			DegreeProgram degreeprogram = SECURITY;

			if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'E') degreeprogram = SECURITY;
				else if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'O') degreeprogram = SOFTWARE;
					else if (studentdata.at(lhs) == 'N') degreeprogram = NETWORK;

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)

{
	int daystocompletearray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daystocompletearray, degreeprogram);
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string emailaddress = (classRosterArray[i]->getEmailAddress());
		if ((emailaddress.find("@") == string::npos) || (emailaddress.find(" ") != string::npos) || (emailaddress.find(".") == string::npos))
		{
			any = true;
			cout << emailaddress << ":" << classRosterArray[i]->getFirstName() << endl;
		}
	}
	if (!any) cout << "NONE" << endl;
}

void Roster::printAverageDays(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			cout << studentID << ":";
			cout << (classRosterArray[i]->getDaysToComplete()[0] +
				classRosterArray[i]->getDaysToComplete()[1] +
				classRosterArray[i]->getDaysToComplete()[2]) / 3 << endl;
			
		}
	}
}

	
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

bool Roster::removeStudentByID(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true;
			if (i < studentDataTable - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[studentDataTable - 1];
				classRosterArray[studentDataTable - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentID << "removed from roster. " << endl;
		this->printAll();
	}
	else cout << studentID << " not found. " << endl;
	return 0;
}

Roster::~Roster()
{
	cout << "Destructor called!" << endl;
	for (int i = 0; i < studentDataTable; i++)
	{
		cout << "Removing Student:" << i + 1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}