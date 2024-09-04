#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

struct Employee {
    string name = "\0";
    int id = -1;
    int salary = -1;
};

void setName(Employee &employee, const string &newName);
string getName(const Employee &employee);

void setId(Employee &employee, int newId);
int getId(const Employee &employee);

void setSalary(Employee &employee, int newSalary);
int getSalary(const Employee &employee);

#endif // EMPLOYEE_H
