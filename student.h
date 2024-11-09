#pragma once
#include <iostream>
#include "degree.h"
using std::string;
using std::cout;

enum class printItem { STUDENTID, FIRSTNAME, LASTNAME, EMAILADDRESS, AGE, DAYSTOCOMPLETE, DEGREEPROGRAM, ALL };

static const string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };

class Student {
public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram);
	const static int daysToCompleteArray = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daystocomplete[daysToCompleteArray];
	DegreeProgram degreeProgram;

public:
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysToComplete(int daystocomplete[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printHeader();

	void print();

	~Student();
};