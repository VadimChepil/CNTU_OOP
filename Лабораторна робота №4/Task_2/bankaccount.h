#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QString>


using namespace std;

class BankAccount
{

public:
    BankAccount();
    BankAccount(const QString& accountNum, const QString& accOwner, double accBalance);

    virtual ~BankAccount();

    // Віртуальні функції
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void displayAccountDetails() const = 0;

    // Гетери та сетери
    QString getAccountNumber();
    QString getOwner();
    double getBalance() ;

    void setAccountNumber(QString& accountNum);
    void setOwner(QString& accOwner);
    void setBalance(double accBalance);

protected:
    QString accountNumber;
    QString accountHolder;
    QString owner;
    double balance;
};


#endif // BANKACCOUNT_H
