#include "bitmap.h"
#include <iostream>
#include <cstring> // For strcpy

// Employee class implementation
Employee::Employee() : empid(0), basicsalary(0.0) {
    strcpy(name, "");
}

Employee::Employee(int id, const char* n, double salary) : empid(id), basicsalary(salary) {
    strncpy(name, n, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0'; // Ensure null-termination
}

double Employee::GetBasicSalary() {
    return basicsalary;
}

void Employee::Display() {
    std::cout << "Employee ID: " << empid << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Basic Salary: " << basicsalary << std::endl;
}

// WageEmployee class implementation
WageEmployee::WageEmployee() : Employee(), hours(0), rate(0) {}

WageEmployee::WageEmployee(int id, const char* n, double salary, int h, int r) 
    : Employee(id, n, salary), hours(h), rate(r) {}

double WageEmployee::CalcNetSalary() {
    return GetBasicSalary() + (hours * rate);
}

bool WageEmployee::IsTaxable() {
    return CalcNetSalary() >= 500000;
}

void WageEmployee::Display() {
    Employee::Display(); // Call base class Display
    std::cout << "Hours Worked: " << hours << std::endl;
    std::cout << "Rate per Hour: " << rate << std::endl;
    std::cout << "Net Salary: " << CalcNetSalary() << std::endl;
}

// SalesPerson class implementation
SalesPerson::SalesPerson() : WageEmployee(), sales(0), comm(0) {}

SalesPerson::SalesPerson(int id, const char* n, double salary, int h, int r, int s, int c) 
    : WageEmployee(id, n, salary, h, r), sales(s), comm(c) {}

double SalesPerson::CalcNetSalary() {
    return WageEmployee::CalcNetSalary() + (sales * comm);
}

bool SalesPerson::IsTaxable() {
    return CalcNetSalary() >= 500000;
}

void SalesPerson::Display() {
    WageEmployee::Display(); // Call base class Display
    std::cout << "Sales: " << sales << std::endl;
    std::cout << "Commission per Sale: " << comm << std::endl;
    std::cout << "Net Salary: " << CalcNetSalary() << std::endl;
}
