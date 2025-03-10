#ifndef INTERN_H
#define INTERN_H

#include "Employee.h"

class Intern : public Employee {
private:
    double stipend;

public:
    Intern(string name, int id, string department, double stipend);
    ~Intern();

    void displayInfo() override;
    double calculateSalary() override;
};

#endif
