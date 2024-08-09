#include "bitmap.h"

Student::Student() : StudentName(""), StudentId(""), TotalMarks(-1) {}

Student::Student(std::string name, std::string id) 
    : StudentName(name), StudentId(id), TotalMarks(-1) {}

std::string Student::GetStudentName() {
    return StudentName;
}

std::string Student::GetStudentId() {
    return StudentId;
}

char Student::CalculateGrade() {
    if (TotalMarks == -1) return '-';
    if (TotalMarks > 100) return '#';
    if (TotalMarks >= 85) return 'O';
    if (TotalMarks >= 61) return 'A';
    if (TotalMarks >= 40) return 'P';
    return 'F';
}

Student::~Student() {}

EngineeringStudent::EngineeringStudent(std::string name, std::string id, int thMarks, int prMarks)
    : Student(name, id), TheoryMarks(thMarks), PractialMarks(prMarks) {
    CalculateMarks();
}

int EngineeringStudent::GetPracticalMarks() {
    return PractialMarks;
}

int EngineeringStudent::GetTheoryMarks() {
    return TheoryMarks;
}

int EngineeringStudent::GetTotalMarks() {
    return TotalMarks;
}

void EngineeringStudent::CalculateMarks() {
    TotalMarks = TheoryMarks + PractialMarks;
}

EngineeringStudent::~EngineeringStudent() {}

ArchitectureStudent::ArchitectureStudent(std::string name, std::string id, int dgMarks, int thMarks)
    : Student(name, id), DesignMarks(dgMarks), ThesisMarks(thMarks) {
    CalculateMarks();
}

int ArchitectureStudent::GetDesignMarks() {
    return DesignMarks;
}

int ArchitectureStudent::GetThesisMarks() {
    return ThesisMarks;
}

int ArchitectureStudent::GetTotalMarks() {
    return TotalMarks;
}

void ArchitectureStudent::CalculateMarks() {
    TotalMarks = DesignMarks + ThesisMarks;
}

ArchitectureStudent::~ArchitectureStudent() {}
