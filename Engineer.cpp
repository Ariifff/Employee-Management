#include "Engineer.h"

Engineer::Engineer(string name, int id, string department, double salary, string deg, string major, int exp)
    : Employee(name, id, department, salary), degree(deg), major(major), exp(exp) {}

Engineer::~Engineer() {}

void Engineer::displayInfo() {
    Employee::displayInfo();
    cout << "Degree: " << degree << endl;
    cout << "Major: " << major << endl;
    cout << "Experience: " << exp << " years" << endl;
}

double Engineer::calculateSalary() {
    return salary;
}
