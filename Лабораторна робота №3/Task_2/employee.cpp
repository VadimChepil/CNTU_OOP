#include "employee.h"

Employee::Employee(string name, int id, int salary, Address addr, Department &dept)
    : name(name), id(id), salary(salary), address(addr), department(dept) {}

string Employee::getName()
{
    return name;
}

int Employee::getId()
{
    return id;
}

int Employee::getSalary()
{
    return salary;
}

Address Employee::getAddress()
{
    return address;
}

Department &Employee::getDepartment()
{
    return department;
}

