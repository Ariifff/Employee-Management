#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    string department;
    double salary;

public:
    Employee(string name, int id, string department, double salary);
    Employee() = default;
    virtual ~Employee();

    virtual void displayInfo();
    virtual double calculateSalary();

    string getName();
    int getId();
    string getDepartment();
    double getSalary();
};

#endif
