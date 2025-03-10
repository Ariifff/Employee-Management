#include "Employee.h"

Employee::Employee(string name, int id, string department, double salary)
    : name(name), id(id), department(department), salary(salary) {}

Employee::~Employee() {}

void Employee::displayInfo() {
    cout << "Employee Name: " << name << endl;
    cout << "Employee ID: " << id << endl;
    cout << "Department: " << department << endl;
    cout << "Salary: $" << salary << endl;
}

double Employee::calculateSalary() {
    return salary;
}

string Employee::getName() {
    return name;
}

int Employee::getId() {
    return id;
}

string Employee::getDepartment() {
    return department;
}

double Employee::getSalary() {
    return salary;
}
