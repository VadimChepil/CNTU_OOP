#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>


using namespace std;

class Employee
{

public:
    // Конструктор за замовчуванням
    Employee() {
        name = "Vadim";
        id = 44557997;
        salary = 10000;
        cout << "Default constructor called!" << endl;
    }

    // Конструктор з параметрами
    Employee(string name, int id, int salary) {
        this->name = name;
        this->id = id;
        this->salary = salary;
        cout << "Constructor with parameters called!" << endl;
    }

    // Конструктор копіюючий
    Employee(const Employee& other) {
        name = other.name;
        id = other.id;
        salary = other.salary;
        cout << "Copy constructor called!" << endl;
    }

    // Деструктор
    ~Employee() {
        cout << "Destructor called!" << endl;
    }

    void setName(string newName);
    string getName();

    void setId(int newId);
    int getId();

    void setSalary(int newSalary);
    int getSalary();

private:
    string name;
    int id;
    int salary;
};


#endif // EMPLOYEE_H
