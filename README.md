# Employee Management System

A console-based **Employee Management System** built in **C++** that models real-world organizational roles using **Object-Oriented Programming (OOP)** concepts like **inheritance**, **polymorphism**, and **encapsulation**. This program allows you to manage employees, calculate salaries, and dynamically handle different roles within a company.

## 🚀 Features

- **Add, Remove, and View Employees** by ID.  
- **Role-based Classes:** Manager, Engineer, Staff, Developer, Intern.  
- **Calculate Total Salary** (including bonuses and stipends).  
- **Change Department Manager** on the fly.  
- **Interactive Console Interface** with input options.

## 🏗️ Class Structure

- **Employee (Base Class)**  
- **Derived Classes:**
  - `Manager`: Includes a bonus.
  - `Engineer`: Has degree, major, and years of experience.
  - `Staff`: Has a specific position.
  - `Developer`: Inherits from both **Engineer** and **Staff**.
  - `Intern`: Receives a stipend instead of salary.

## 🛠️ Technologies Used

- **Language:** C++
- **STL (Standard Template Library):** Vectors, Algorithms

## 📂 File Structure
```
├── employee_management.cpp   # Main program file
└── README.md                 # Project documentation (this file)
```

## 🛠️ How to Run
1. **Compile the code:**
```sh
g++ employee_management.cpp -o employee_management
```

2. **Run the executable:**
```sh
./employee_management
```

3. **Follow the console instructions** to manage employees, view details, or calculate salaries.

## 📘 Example Usage
```
Choose one of the following options:
1. Create new Company.
2. Change the Manager of a Department.
3. Add a new Employee to Company.
4. Remove Employee by ID.
5. Show Employee by ID.
6. Show all Employees in Company.
7. Calculate Total Salary.
8. Delete Company.
9. End.
```

## 🟡 Future Improvements
- **File Persistence:** Save and load employee data.
- **Error Handling Enhancements:** Improve input validation.
- **GUI Integration:** Add a graphical interface with libraries like **Qt**.

## 👨‍💻 Author
Mohd Arif Rainee
