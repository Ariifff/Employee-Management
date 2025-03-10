#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string name, int id, string department, double salary, double bonus);
    ~Manager();

    void displayInfo() override;
    double calculateSalary() override;
};

#endif
