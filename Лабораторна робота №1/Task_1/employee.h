#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee
{

public:
    Employee();

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
