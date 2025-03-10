#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <numeric>
using namespace std;

// Base class: Employee
class Employee {
protected:
    string name;
    int id;
    string department;
    double salary;

public:
    Employee(string name, int id,string department, double salary) {
        this->name = name;
        this->id = id;
        this->department=department;
        this->salary = salary;
    }
    Employee()=default;
    
    virtual ~Employee() {}

    virtual void displayInfo() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
        cout<<"Department: "<<department<<endl;
        cout << "Salary: $"  << salary << endl;
    }
    

    virtual double calculateSalary() {
        return salary;
    }

    string getName() {
        return name;
    }

    int getId() {
        return id;
    }

	string getDepartment(){
	   return department;
	}
	
    double getSalary() {
        return salary;
    }
};

class Engineer: virtual public Employee{
private:
	string degree;
	string major;
	int exp;
public:
	Engineer(string name, int id,string department, double salary, string deg, string major,int exp)
        : Employee(name, id, department, salary), degree(deg), major(major),exp(exp) {}
        
	~Engineer() {}
        
	void displayInfo() override {
		Employee::displayInfo();
		cout<<"Degree: "<<degree<<endl;
		cout<<"Major: "<<major<<endl;
		cout<<"Experience: "<<exp<<"years"<<endl;
	}
	double calculateSalary() override{
		return salary;
	}	
};

class Staff : virtual public Employee {
private:
	string position;
	
public:
	Staff(string name, int id,string department, double salary, string pos)
        : Employee(name, id, department, salary), position(pos) {}
	Staff()=default;

	~Staff() {}
	
	string& getPos(){
		return position;
	}
	void setPos(string pos){
		position=pos;
	}
	void displayInfo() override {
		Employee::displayInfo();
		cout<<"Position: "<<position<<endl;
	}
	double calculateSalary() override{
		return salary;
	}	
};

// Derived class: Manager (inherits from Employee)
class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string name, int id,string department, double salary, double bonus)
        : Employee(name, id, department, salary), bonus(bonus) {}
        
    ~Manager() {}

    void displayInfo() override {
        Employee::displayInfo();
        cout << "Bonus: $"  << bonus << endl;
    }

    double calculateSalary() override {
        return salary + bonus;
    }
};

// Derived class: Developer (inherits from Employee)
class Developer : public Staff, public Engineer {
private:
    string programmingLanguage;

public:
    Developer(string name, int id,string department, double salary, string position, string degree, string major, int exp, string programmingLanguage)
        : Employee(name, id, department, salary), Engineer(name, id, department, salary, degree, major, exp), programmingLanguage(programmingLanguage) {
		Staff::setPos(position);
	 }
        
    ~Developer() {}

    void displayInfo() override {
        Engineer::displayInfo();
        cout<<"Position: "<<Staff::getPos()<<endl;
        cout << "Programming Language: " << programmingLanguage << endl;
    }

    double calculateSalary() override {
        return salary; // Developers don't have bonus by default
    }
};

// Derived class: Intern (inherits from Employee)
class Intern : public Employee {
private:
    double stipend;

public:
    Intern(string name, int id,string department, double stipend)
        : Employee(name, id, department, 0), stipend(stipend) {}
        
    ~Intern() {}

    void displayInfo() override {
        Employee::displayInfo();
        cout << "Stipend: $"  << stipend << endl;
    }

    double calculateSalary() override {
        return stipend;
    }
};

// Company class to manage employees
class Company {
private:
    vector<Employee*> employees;

public:
	Company(){
		cout<<"Company created successfully!"<<endl;
	}
	
    ~Company() {
        for (auto e : employees) {
            delete e;
        }
        cout<<"Company deleted successfully!"<<endl;
    }

    void addEmployee(Employee* employee) {
        employees.push_back(employee);
        cout<<"Employee "<<employee->getName()<<" added to Company!"<<endl;
    }
    
    void removeEmployee(int id){
    	for (auto e : employees){
    		if (e->getId()==id){
    			employees.erase(find(employees.begin(),employees.end(),e));
    		cout<<"Employee "<<e->getName()<<" removed from Company!"<<endl;
    		return;}
    	}
    	cout<<"Employee with ID not found!"<<endl;
    }
    
    void changeManager(string department, string chname, int chbonus){
    	for (auto e : employees){
    		if ((typeid(*e) == typeid(Manager)) and (e->getDepartment()==department)){
    			Employee* emp= new Manager(chname, e->getId(), e->getDepartment(),e->getSalary(), chbonus);
    			replace(employees.begin(),employees.end(),e, emp);
    			cout<<"Department Manager successfully changed for "<<department<<" Department!"<<endl;
    			return;}
    	}
    	cout<<"Manager to be replaced not found!"<<endl;
    }
    
    int totalSal(){
    	vector<int> salaries;
    	for_each(employees.begin(), employees.end(), [&](Employee* a){
    		salaries.push_back(a->calculateSalary());
    	});
		return accumulate(salaries.begin(), salaries.end(), 0, [](int a, int b)->int{
		  return a+b;
		});
    }
    void displayAllEmployees() {
        for (auto e : employees) {
            e->displayInfo();
            cout << "Total Salary: $"  << e->calculateSalary() << endl;
            cout << "----------------------------------" << endl;
        }
    }

    void displayEmployeeById(int id) {
        for (auto e : employees) {
            if (e->getId() == id) {
                e->displayInfo();
                cout << "Total Salary: $"  << e->calculateSalary() << endl;
                return;
            }
        }
        cout << "Employee with ID " << id << " not found!" << endl;
    }
};

int main() {
    int n=0;
    int n1=0;
    string name, dep, pos, deg, major, prog;
    int id, sal, bonus, year, stipend;
    Company *c;
    while(n!=9){
     	cout << "----------------------------------" << endl;
	    cout<<"Choose one of the following options: "<<endl;
	    cout<<"1. Create new Company."<<endl;
	    cout<<"2. Change the Manager of a Department."<<endl;
	    cout<<"3. Add a new Employee to Company."<<endl;
	    cout<<"4. Remove Employee by ID."<<endl;
	    cout<<"5. Show Employee by ID."<<endl;
	    cout<<"6. Show all Employees in Company."<<endl;
	    cout<<"7. Calculate Total Salary."<<endl;
	    cout<<"8. Delete Company. "<<endl;
	    cout<<"9. End."<<endl;
	    cout << "----------------------------------" << endl;
	    cin>>n;
	    switch(n){
	    case 1:
	    	c=new Company;
	    	break;
	    case 2:
	    	cout<<"Enter name of Department: ";   cin>>dep;
	    	cout<<"Enter name of new Manager: ";   cin>>name;
	    	cout<<"Enter bonus for new Manager: ";   cin>>bonus;
	    	c->changeManager(dep, name, bonus);
	    	break;
	    case 3:
	    	cout<<"Enter name: ";   cin>>name;
	    	cout<<"Enter ID: ";   cin>>id;
	    	cout<<"Enter department: ";   cin>>dep;
	    	cout<<"Enter salary: ";   cin>>sal;
	    	cout<<"Choose one of the following employee type: "<<endl;
	    	cout<<"1. Manager"<<endl;
	    	cout<<"2. Staff"<<endl;
	    	cout<<"3. Engineer"<<endl;
	    	cout<<"4. Developer"<<endl;
	    	cout<<"5. Intern"<<endl;
	    	cin>>n1;
	    	switch(n1){
	    	case 1:
	    		cout<<"Enter bonus: ";   cin>>bonus;
	    		c->addEmployee(new Manager(name, id, dep, sal, bonus));
	    		break;
	    	case 2:
	    		cout<<"Enter position: ";  cin>>pos;
	    		c->addEmployee(new Staff(name, id, dep, sal, pos));
	    		break;
	    	case 3:
	    		cout<<"Enter Degree: ";   cin>>deg;
	    		cout<<"Enter Major: ";   cin>>major;
	    		cout<<"Enter Years of Experience: ";   cin>>year;
	    		c->addEmployee(new Engineer(name, id, dep, sal, deg, major, year));
	    		break;
	    	case 4:
	    		cout<<"Enter position: ";   cin>>pos;
	    		cout<<"Enter Degree: ";   cin>>deg;
	    		cout<<"Enter Major: ";   cin>>major;
	    		cout<<"Enter Years of Experience: ";    cin>>year;
	    		cout<<"Enter Programming Language: ";    cin>>prog;
	    		c->addEmployee(new Developer(name, id, dep, sal, pos, deg, major, year, prog));
	    		break;
	    	case 5:
	    		cout<<"Enter Stipend: ";    cin>>stipend;
	    		c->addEmployee(new Intern(name, id, dep, stipend));
	    		break;
	    	default:
	    		cout<<"Invalid Input!! Try again..."<<endl;
	    		break;
	    	}
	    	break;
	    case 4:
	    	cout << "Enter employee ID to delete: ";
	    	cin >> id;
	    	c->removeEmployee(id);
	    	break;
	    case 5:
	    	cout << "Enter employee ID to search: ";
	    	cin >> id;
	    	c->displayEmployeeById(id);
	    	break;
	    case 6:
	    	cout << "Company Employees:" << endl;
	    cout << "-------------------" << endl;
	    c->displayAllEmployees();
	    	break;
	    case 7:
	    	cout<<"Total Salary of Employees: "<<c->totalSal()<<endl;
	    	break;
	    case 8:
	    	delete c;
	    	break;
	    case 9:
	    	break;
	    default:
	    	cout<<"Invalid Input!! Try again..."<<endl;
	    	break;
	    }
    }
    return 0;
}
