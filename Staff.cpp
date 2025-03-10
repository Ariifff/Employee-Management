#include "Staff.h"

Staff::Staff(string name, int id, string department, double salary, string pos)
    : Employee(name, id, department, salary), position(pos) {}

Staff::~Staff() {}

string& Staff::getPos() {
    return position;
}

void Staff::setPos(string pos) {
    position = pos;
}

void Staff::displayInfo() {
    Employee::displayInfo();
    cout << "Position: " << position << endl;
}

double Staff::calculateSalary() {
    return salary;
}
