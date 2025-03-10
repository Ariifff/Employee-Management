#include "Employee.h"
#include "Engineer.h"
#include "Staff.h"
#include "Developer.h"
#include "Intern.h"
#include "Manager.h"
#include "Company.h"
#include <iostream>
using namespace std;

int main() {
    Company company;
    
    int choice;
    while (true) {
        cout << "----------------------------------" << endl;
        cout << "1. Add Employee\n";
        cout << "2. Remove Employee\n";
        cout << "3. Display All Employees\n";
        cout << "4. Display Employee by ID\n";
        cout << "5. Calculate Total Salary\n";
        cout << "6. Exit\n";
        cout << "----------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) break;

        switch (choice) {
            case 1: {
                string name, department, position, degree, major, progLang;
                int id, salary, exp, bonus, stipend;
                int type;
                
                cout << "Enter Employee Type (1-Manager, 2-Staff, 3-Engineer, 4-Developer, 5-Intern): ";
                cin >> type;
                cout << "Enter Name: "; cin >> name;
                cout << "Enter ID: "; cin >> id;
                cout << "Enter Department: "; cin >> department;
                cout << "Enter Salary: "; cin >> salary;
                
                if (type == 1) {
                    cout << "Enter Bonus: "; cin >> bonus;
                    company.addEmployee(new Manager(name, id, department, salary, bonus));
                } else if (type == 2) {
                    cout << "Enter Position: "; cin >> position;
                    company.addEmployee(new Staff(name, id, department, salary, position));
                } else if (type == 3) {
                    cout << "Enter Degree: "; cin >> degree;
                    cout << "Enter Major: "; cin >> major;
                    cout << "Enter Experience (years): "; cin >> exp;
                    company.addEmployee(new Engineer(name, id, department, salary, degree, major, exp));
                } else if (type == 4) {
                    cout << "Enter Position: "; cin >> position;
                    cout << "Enter Degree: "; cin >> degree;
                    cout << "Enter Major: "; cin >> major;
                    cout << "Enter Experience (years): "; cin >> exp;
                    cout << "Enter Programming Language: "; cin >> progLang;
                    company.addEmployee(new Developer(name, id, department, salary, position, degree, major, exp, progLang));
                } else if (type == 5) {
                    cout << "Enter Stipend: "; cin >> stipend;
                    company.addEmployee(new Intern(name, id, department, stipend));
                }
                break;
            }
            
            case 2: {
                int id;
                cout << "Enter Employee ID to remove: ";
                cin >> id;
                company.removeEmployee(id);
                break;
            }
            
            case 3:
                company.displayAllEmployees();
                break;

            case 4: {
                int id;
                cout << "Enter Employee ID: ";
                cin >> id;
                company.displayEmployeeById(id);
                break;
            }
            
            case 5:
                cout << "Total Salary of Employees: $" << company.totalSal() << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
