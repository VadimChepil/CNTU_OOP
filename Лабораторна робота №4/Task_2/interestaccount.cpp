#include "interestaccount.h"

InterestAccount::InterestAccount() : BankAccount(), interestRate(0.0) {}

InterestAccount::InterestAccount(const QString &accNumber, const QString &holder, double bal, double rate)
    : BankAccount(accNumber, holder, bal), interestRate(rate)
{
    if (rate < 0 || rate > 1)
    {
        throw invalid_argument("Interest rate must be between 0 and 1.");
    }
}

void InterestAccount::setInterestRate(double rate)
{
    if (rate < 0 || rate > 1)
    {
        throw invalid_argument("Interest rate must be between 0 and 1.");
    }
    interestRate = rate;
}

double InterestAccount::getInterestRate()
{
    return interestRate;
}

void InterestAccount::addInterest()
{
    balance += balance * interestRate;
}

void InterestAccount::withdraw(double amount)
{
    if (amount > balance)
    {
        throw invalid_argument("Insufficient balance.");
    }
    balance -= amount;
}

void InterestAccount::deposit(double amount)
{
    if (amount <= 0)
    {
        throw invalid_argument("Deposit amount must be positive.");
    }
    balance += amount;
}

void InterestAccount::displayAccountDetails() const
{
    cout << "Interest Account: " << accountNumber.toStdString() << "\n"
         << "Holder: " << accountHolder.toStdString() << "\n"
         << "Balance: " << balance << "\n"
         << "Interest Rate: " << interestRate << "\n";
}
