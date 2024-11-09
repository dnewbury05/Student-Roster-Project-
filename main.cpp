// WGU Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <array>
using namespace std;

int main()
{
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "C++" << endl;
    cout << "Daniel Newbury" << endl;
    cout << "012303998" << endl;

    const string studentData[] =
    { 
      "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_Lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Daniel,Newbury,dnewbury0505@gmail.com,24,35,20,30,SOFTWARE" 
    };
    const int studentDataTable = 5;
    Roster roster;

    for (int i = 0; i < studentDataTable; i++) roster.parse(studentData[i]);
    cout << "Showing All Students:" << endl;
    roster.printAll();
    cout << endl;

    cout << "Showing Software Students:" << endl;
    roster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Showing Invalid Email Address: " << endl;
    roster.printInvalidEmails();
    cout << endl;

    cout << "Showing Average Days Per Class: " << endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        roster.printAverageDays(roster.classRosterArray[i]->getStudentID());
    }
    cout << endl;

    cout << "Remove student A3." << endl;
    roster.removeStudentByID("A3");
    cout << endl;

    cout << "Remove student A3." << endl;
    roster.removeStudentByID("A3");
    cout << endl << endl;

    return 0;

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
