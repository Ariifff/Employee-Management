#ifndef ENGINEER_H
#define ENGINEER_H

#include "Employee.h"

class Engineer : virtual public Employee {
private:
    string degree;
    string major;
    int exp;

public:
    Engineer(string name, int id, string department, double salary, string deg, string major, int exp);
    ~Engineer();

    void displayInfo() override;
    double calculateSalary() override;
};

#endif
