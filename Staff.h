#ifndef STAFF_H
#define STAFF_H

#include "Employee.h"

class Staff : virtual public Employee {
private:
    string position;

public:
    Staff(string name, int id, string department, double salary, string pos);
    ~Staff();

    string& getPos();
    void setPos(string pos);

    void displayInfo() override;
    double calculateSalary() override;
};

#endif
