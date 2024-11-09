#pragma once
#include "student.h"

class Roster
{
public:
	int lastIndex = -1;
	const static int studentDataTable = 5;
	Student* classRosterArray[studentDataTable];

	void parse(string row);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void printAll();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	void printInvalidEmails();
	void printAverageDays(string studentID);
	bool removeStudentByID(string studentID);
	~Roster();
};