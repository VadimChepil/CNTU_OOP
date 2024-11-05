#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

class Manager : public Employee
{
public:
    Manager(string name, int id, int salary, Address addr, Department& dept, int bonus);

    void setBonus(int newBonus);

    int getBonus();

private:
    int bonus;
};

#endif // MANAGER_H
