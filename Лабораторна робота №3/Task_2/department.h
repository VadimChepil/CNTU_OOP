#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>

using namespace std;

class Department
{
public:
    Department(string name);

    string getName();

    void setName(string newName);

private:
    string name;
};

#endif // DEPARTMENT_H
