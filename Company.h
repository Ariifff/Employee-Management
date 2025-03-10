#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
#include <algorithm>
#include <numeric>
#include "Employee.h"

class Company {
private:
    vector<Employee*> employees;

public:
    Company();
    ~Company();

    void addEmployee(Employee* employee);
    void removeEmployee(int id);
    void changeManager(string department, string chname, int chbonus);
    int totalSal();
    void displayAllEmployees();
    void displayEmployeeById(int id);
};

#endif
