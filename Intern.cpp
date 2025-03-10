#include "Intern.h"

Intern::Intern(string name, int id, string department, double stipend)
    : Employee(name, id, department, 0), stipend(stipend) {}

Intern::~Intern() {}

void Intern::displayInfo() {
    Employee::displayInfo();
    cout << "Stipend: $" << stipend << endl;
}

double Intern::calculateSalary() {
    return stipend;
}
