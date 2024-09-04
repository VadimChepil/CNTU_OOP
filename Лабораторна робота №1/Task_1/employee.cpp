#include "employee.h"

Employee::Employee() {}

void Employee::setName(string newName)
{
    name = newName;
}

string Employee::getName()
{
    return name;
}

void Employee::setId(int newId)
{
    id = newId;
}

int Employee::getId()
{
    return id;
}

void Employee::setSalary(int newSalary)
{
    salary = newSalary;
}

int Employee::getSalary()
{
    return salary;
}

