#ifndef REGULARACCOUNT_H
#define REGULARACCOUNT_H

#include "BankAccount.h"

class RegularAccount : public BankAccount
{

public:
    RegularAccount() : BankAccount(), minimumBalance(0.0) {}
    RegularAccount(const QString &accNumber, const QString &holder, double bal, double minBal);

    void setMinBalance(double minBal);
    double getMinBalance();

    // Перевизначення функцій
    void deposit(double amount) override;
    void withdraw(double amount) override;
    void displayAccountDetails() const override;

private:
    double minimumBalance;

};

#endif // REGULARACCOUNT_H
