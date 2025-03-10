#include "Developer.h"

Developer::Developer(string name, int id, string department, double salary, string position, string degree, string major, int exp, string programmingLanguage)
    : Employee(name, id, department, salary), Engineer(name, id, department, salary, degree, major, exp), programmingLanguage(programmingLanguage) {
    Staff::setPos(position);
}

Developer::~Developer() {}

void Developer::displayInfo() {
    Engineer::displayInfo();
    cout << "Position: " << Staff::getPos() << endl;
    cout << "Programming Language: " << programmingLanguage << endl;
}

double Developer::calculateSalary() {
    return salary;
}
