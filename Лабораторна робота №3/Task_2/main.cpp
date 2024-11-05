#include <iostream>
#include "employee.h"
#include "address.h"
#include "department.h"
#include "manager.h"

using namespace std;

int main()
{
    Address address1("Shevchenka St.", "Kyiv");
    Address address2("Kovalenka St.", "Kyiv");

    Department dept("IT");
    Employee employee("Taras", 1, 15000, address1, dept);
    Manager manager("Oleg", 2, 150000, address2, dept, 100);

    cout << "Name: " << employee.getName() << endl;
    cout << "ID: " << employee.getId() << endl;
    cout << "Salary: " << employee.getSalary() << endl;
    cout << "Address: " << employee.getAddress().getStreet() << ", " << employee.getAddress().getCity() << endl;
    cout << "Department: " << employee.getDepartment().getName() << endl;

    cout << endl;
    cout << "Name: " << manager.getName() << endl;
    cout << "ID: " << manager.getId() << endl;
    cout << "Salary: " << manager.getSalary() << endl;
    cout << "Address: " << manager.getAddress().getStreet() << ", " << employee.getAddress().getCity() << endl;
    cout << "Department: " << manager.getDepartment().getName() << endl;
    cout << "Bonus: " << manager.getBonus() << endl;


    return 0;
}
