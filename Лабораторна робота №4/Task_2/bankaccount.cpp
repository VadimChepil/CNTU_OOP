#include "bankaccount.h"

BankAccount::BankAccount() : accountNumber("Unknown"), accountHolder("Unknown"), balance(0.0) {}

BankAccount::BankAccount(const QString &accountNum, const QString &accOwner, double accBalance)
    : accountNumber(accountNum), owner(accOwner), balance(accBalance)
{
    if (balance < 0) {
        throw invalid_argument("Initial balance cannot be negative");
    }
}

BankAccount::~BankAccount() {}

QString BankAccount::getAccountNumber()
{
    return accountNumber;
}

QString BankAccount::getOwner()
{
    return owner;
}

double BankAccount::getBalance()
{
    return balance;
}

void BankAccount::setAccountNumber(QString &accountNum)
{
    accountNumber = accountNum;
}

void BankAccount::setOwner(QString &accOwner)
{
    owner = accOwner;
}

void BankAccount::setBalance(double accBalance)
{
    balance = accBalance;
}
