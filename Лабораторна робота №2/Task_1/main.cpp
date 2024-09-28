#include <Employee.h>

using namespace std;

int main()
{
    // Використання значень за замовчуванням
    Employee Human1;
    cout << "Name human1: " << Human1.getName() << endl;
    cout << "Id human1: " << Human1.getId() << endl;
    cout << "Salary human1: " << Human1.getSalary() << "$" << endl;
    cout << " " << endl;

    // Створення об'єкта з параметрами
    Employee Human2("Oleg", 5454545, 50000);
    cout << "Name human2: " << Human2.getName() << endl;
    cout << "Id human2: " << Human2.getId() << endl;
    cout << "Salary human2: " << Human2.getSalary() << "$" << endl;
    cout << " " << endl;

    // Копіюювання даних об'єкта
    Employee Human3(Human1);
    cout << "Name human3: " << Human3.getName() << endl;
    cout << "Id human3: " << Human3.getId() << endl;
    cout << "Salary human3: " << Human3.getSalary() << "$" << endl;
    cout << " " << endl;
    return 0;
}
