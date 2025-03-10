#include "Company.h"
#include "Manager.h"
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

Company::Company() {
    cout << "Company created successfully!" << endl;
}

Company::~Company() {
    for (auto e : employees) {
        delete e;
    }
    cout << "Company deleted successfully!" << endl;
}

void Company::addEmployee(Employee* employee) {
    employees.push_back(employee);
    cout << "Employee " << employee->getName() << " added to Company!" << endl;
}

void Company::removeEmployee(int id) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if ((*it)->getId() == id) {
            cout << "Employee " << (*it)->getName() << " removed from Company!" << endl;
            delete *it;
            employees.erase(it);
            return;
        }
    }
    cout << "Employee with ID not found!" << endl;
}

void Company::changeManager(string department, string chname, int chbonus) {
    for (auto e : employees) {
        if ((typeid(*e) == typeid(Manager)) && (e->getDepartment() == department)) {
            Employee* emp = new Manager(chname, e->getId(), e->getDepartment(), e->getSalary(), chbonus);
            replace(employees.begin(), employees.end(), e, emp);
            delete e;
            cout << "Department Manager successfully changed for " << department << " Department!" << endl;
            return;
        }
    }
    cout << "Manager to be replaced not found!" << endl;
}

int Company::totalSal() {
    vector<int> salaries;
    for_each(employees.begin(), employees.end(), [&](Employee* a) {
        salaries.push_back(a->calculateSalary());
    });
    return accumulate(salaries.begin(), salaries.end(), 0);
}

void Company::displayAllEmployees() {
    for (auto e : employees) {
        e->displayInfo();
        cout << "Total Salary: $" << e->calculateSalary() << endl;
        cout << "----------------------------------" << endl;
    }
}

void Company::displayEmployeeById(int id) {
    for (auto e : employees) {
        if (e->getId() == id) {
            e->displayInfo();
            cout << "Total Salary: $" << e->calculateSalary() << endl;
            return;
        }
    }
    cout << "Employee with ID " << id << " not found!" << endl;
}
