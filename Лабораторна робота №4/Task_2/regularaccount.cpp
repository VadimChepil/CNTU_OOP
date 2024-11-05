#include "regularaccount.h"
#include <iostream>

using namespace std;

RegularAccount::RegularAccount(const QString &accNumber, const QString &holder, double bal, double minBal)
    : BankAccount(accNumber, holder, bal), minimumBalance(minBal)
{
    if (bal < minimumBalance)
    {
        throw invalid_argument("Initial balance cannot be less than minimum balance.");
    }
}

void RegularAccount::setMinBalance(double minBal)
{
    minimumBalance = minBal;
}

double RegularAccount::getMinBalance()
{
    return minimumBalance;
}

void RegularAccount::withdraw(double amount)
{
    if (balance - amount < minimumBalance)
    {
        throw invalid_argument("Withdrawal would breach the minimum balance.");
    }
    balance -= amount;
}

void RegularAccount::deposit(double amount)
{
    if (amount <= 0)
    {
        throw invalid_argument("Deposit amount must be positive.");
    }
    balance += amount;
}


void RegularAccount::displayAccountDetails() const
{
    cout << "Regular Account: " << accountNumber.toStdString() << "\n"
         << "Holder: " << accountHolder.toStdString() << "\n"
         << "Balance: " << balance << "\n"
         << "Minimum Balance: " << minimumBalance << "\n";
}
