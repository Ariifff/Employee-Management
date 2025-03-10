#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Staff.h"
#include "Engineer.h"

class Developer : public Staff, public Engineer {
private:
    string programmingLanguage;

public:
    Developer(string name, int id, string department, double salary, string position, string degree, string major, int exp, string programmingLanguage);
    ~Developer();

    void displayInfo() override;
    double calculateSalary() override;
};

#endif
