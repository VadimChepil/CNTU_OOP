#include "employee.h"

void setName(Employee &employee, const string &newName)
{
    employee.name = newName;
}

string getName(const Employee &employee)
{
    return employee.name;
}

void setId(Employee &employee, int newId)
{
    employee.id = newId;
}

int getId(const Employee &employee)
{
    return employee.id;
}

void setSalary(Employee &employee, int newSalary)
{
    employee.salary = newSalary;
}

int getSalary(const Employee &employee)
{
    return employee.salary;
}
