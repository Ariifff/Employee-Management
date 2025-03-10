#include "Manager.h"

Manager::Manager(string name, int id, string department, double salary, double bonus)
    : Employee(name, id, department, salary), bonus(bonus) {}

Manager::~Manager() {}

void Manager::displayInfo() {
    Employee::displayInfo();
    cout << "Bonus: $" << bonus << endl;
}

double Manager::calculateSalary() {
    return salary + bonus;
}
