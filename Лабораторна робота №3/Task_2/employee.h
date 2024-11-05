#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "address.h"
#include "department.h"

using namespace std;

class Employee
{

public:
    Employee(string name, int id, int salary, Address addr, Department& dept);

    string getName();
    int getId();
    int getSalary();
    Address getAddress();
    Department& getDepartment();

private:
    string name;
    int id;
    int salary;
    Address address; // композиція
    Department& department; // посилання
};


#endif // EMPLOYEE_H
