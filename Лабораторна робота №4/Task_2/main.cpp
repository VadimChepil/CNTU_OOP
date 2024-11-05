#include <QCoreApplication>
#include "RegularAccount.h"
#include "InterestAccount.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try
    {
        RegularAccount regAcc("12345", "John Doe", 500, 100);
        regAcc.deposit(200);
        regAcc.withdraw(300);
        regAcc.displayAccountDetails();

        InterestAccount intAcc("54321", "Jane Smith", 1000, 0.05);
        intAcc.addInterest();
        intAcc.displayAccountDetails();
    }
    catch (exception &e)
    {
        cerr << "Error: " << e.what() << std::endl;
    }

    return a.exec();
}
