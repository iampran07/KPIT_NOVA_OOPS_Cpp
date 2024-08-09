#include "bitmap.h"

Employee::Employee()
    : EmployeeId(""), EmployeeName(""), EmployeeSalary(0.0f), PaidLeavesCount(0), PaidLeavesClaimed(0) {}

Employee::Employee(std::string id, std::string name, float salary, int plCount, int plClaimed)
    : EmployeeId(id), EmployeeName(name), EmployeeSalary(salary), PaidLeavesCount(plCount), PaidLeavesClaimed(plClaimed) {}

Employee::~Employee() {}

void Employee::ChangeName(std::string newName) {
    EmployeeName = newName;
}

float Employee::CalculateLeavesReimbursement() {
    int unclaimedLeaves = PaidLeavesCount - PaidLeavesClaimed;
    return (EmployeeSalary / 30.0f) * static_cast<float>(unclaimedLeaves);
}

int Employee::GetPaidLeavesCount() {
    return PaidLeavesCount;
}

int Employee::GetClaimedPaidLeavesCount() {
    return PaidLeavesClaimed;
}

float Employee::GetEmployeeSalary() {
    return EmployeeSalary;
}

std::string Employee::GetEmployeeName() {
    return EmployeeName;
}

std::string Employee::GetEmployeeId() {
    return EmployeeId;
}

Manager::Manager()
    : Employee(), ProjectsCompleted(0), ManagerDepartment("") {}

Manager::Manager(std::string id, std::string name, float salary, int plCount, 
                  int plClaimed, int projects, std::string department)
    : Employee(id, name, salary, plCount, plClaimed), ProjectsCompleted(projects), ManagerDepartment(department) {}

Manager::~Manager() {}

float Manager::CalculateBonus() {
    return static_cast<float>(ProjectsCompleted) * GetEmployeeSalary();
}

std::string Manager::GetManagerDepartment() {
    return ManagerDepartment;
}

int Manager::GetProjectsCompletedCount() {
    return ProjectsCompleted;
}
