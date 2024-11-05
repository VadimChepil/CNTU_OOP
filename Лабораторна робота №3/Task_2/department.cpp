#include "department.h"

Department::Department(string name) : name(name) {}

string Department::getName()
{
    return name;
}

void Department::setName(string newName)
{
    name = newName;
}
