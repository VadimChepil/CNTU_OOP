#ifndef INTERESTACCOUNT_H
#define INTERESTACCOUNT_H

#include "BankAccount.h"
#include <iostream>

using namespace std;

class InterestAccount : public BankAccount
{

public:
    InterestAccount();
    InterestAccount(const QString &accNumber,const  QString &holder, double bal, double rate);

    void setInterestRate(double rate);
    double getInterestRate();

    void addInterest();

    // Перевизначення функцій
    void withdraw(double amount) override;
    void deposit(double amount) override;
    void displayAccountDetails() const override;

private:
    double interestRate;
};

#endif // INTERESTACCOUNT_H
