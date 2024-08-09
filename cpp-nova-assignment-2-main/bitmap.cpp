#include<iostream>
#include<cstring>
#include"bitmap.h"
using namespace std;

Student::Student()
{
	strcpy(name, "Unknown");
    for (int i = 0; i < 5; i++) {
        marks[i] = 0;
    }
}

Student::Student(int r, const char *n, int m1, int m2, int m3, int m4, int m5) // here m1,m2,m3,m4 and m5 are marks in each subject
{
	// code here
	strcpy(name, n);
    marks[0] = m1;
    marks[1] = m2;
    marks[2] = m3;
    marks[3] = m4;
    marks[4] = m5;
	
}

void Student::Accept()
{
	// code here
	cout << "Enter Roll Number: ";
    cin >> rollno;
    cin.ignore(); // To ignore newline character left in the input buffer
    cout << "Enter Name: ";
    cin.getline(name, 20);
    cout << "Enter marks in 5 subjects: ";
    for (int i = 0; i < 5; i++) {
        cin >> marks[i];
    }
}


void Student::Display()
{
	// code here
	cout << "Roll Number: " << rollno << endl;
    cout << "Name: " << name << endl;
    cout << "Marks in 5 subjects: ";
    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;
}

float Student::calcAverage()
{
	float avg;
    for (int i = 0; i < 5; i++) {
        avg += marks[i];
    }
	return avg/ 5.0f;
}

char Student::calcGrade()
{
	// code here
	float average = calcAverage();
    if (average >= 60) {
        return 'A';
    } else if (average >= 50) {
        return 'B';
    } else if (average >= 40) {
        return 'C';
    } else {
        return 'D';
    }
}

int Student::highestMarks()
{
	int highest = marks[0];
    for (int i = 1; i < 5; i++) {
        if (marks[i] > highest) {
            highest = marks[i];
        }
    }
    return highest;
}

int Student::lowestMarks()
{
	int lowest = marks[0];
    for (int i = 1; i < 5; i++) {
        if (marks[i] < lowest) {
            lowest = marks[i];
        }
    }
    return lowest;
}

void Student::showResult() {
    Display();
    cout << "Average Marks: " << calcAverage() << endl;
    cout << "Grade: " << calcGrade() << endl;
    cout << "Highest Marks: " << highestMarks() << endl;
    cout << "Lowest Marks: " << lowestMarks() << endl;
}


































