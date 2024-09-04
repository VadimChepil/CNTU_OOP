#include <iostream>
#include <employee.h>

using namespace std;

int main()
{
    Employee Human;
    setName(Human, "Taras");
    setId(Human, 87891561);
    setSalary(Human, 15000);

    cout << "Name human: " << getName(Human) << endl;
    cout << "Id human: " << getId(Human) << endl;
    cout << "Salary human: " << getSalary(Human) << "$" << endl;

    return 0;
}
