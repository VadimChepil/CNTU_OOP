#include <iostream>
#include <Employee.h>

using namespace std;

int main()
{
    Employee Human;
    Human.setName("Taras");
    Human.setId(87891561);
    Human.setSalary(15000);

    cout << "Name human: " << Human.getName() << endl;
    cout << "Id human: " << Human.getId() << endl;
    cout << "Salary human: " << Human.getSalary() << "$" << endl;

    return 0;
}
