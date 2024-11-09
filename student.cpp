#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysToCompleteArray; i++) this->daystocomplete[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daystocomplete[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysToCompleteArray; i++) this->daystocomplete[i] = daystocomplete[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysToComplete() { return this->daystocomplete; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int Age) { this->age = age; }
void Student::setDaysToComplete(int daystocomplete[])
{
	for (int i = 0; i < daysToCompleteArray; i++) this->daystocomplete[i] = daystocomplete[i];
}
void Student::setDegreeProgram(DegreeProgram degreeprogram) { this->degreeProgram = degreeprogram; }

void Student::printHeader()
{
	cout << "ID" << '\t' << "First" << '\t' << "Last" << '\t' << "Email" << '\t' << "Age" << '\t' << "Days to Complete" << '\t' << "Degree" << endl;
}

void Student::print()
{
	cout << this->getStudentID() <<'\t';
	cout << this->getFirstName() <<'\t'; 
	cout << this->getLastName() <<'\t';
	cout << this->getEmailAddress() <<'\t';
	cout << this->getAge() <<'\t';
	cout << this->getDaysToComplete()[0] << ',';
	cout << this->getDaysToComplete()[1] << ',';
	cout << this->getDaysToComplete()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}