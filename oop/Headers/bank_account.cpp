#include <iostream>
#include "bank_account.hpp"

using namespace std;

BankAccount::BankAccount(double balance) : balance(balance) {}

void BankAccount::deposit(double plus)
{
    cout << "Adding deposit:\n";
    if (plus < 0)
    {
        cout << "Invalid Input.\n";
        return;
    }
    this->balance += plus;
    cout << "New Balance = " << this->balance << '\n';
}

void BankAccount::withdraw(double mins)
{
    cout << "Adding withdraw:\n";
    if (mins < 0)
    {
        cout << "Invalid Input.\n";
        return;
    }
    this->balance -= mins;
    cout << "New Balance = " << this->balance << '\n';
}

double BankAccount::getBalance()
{
    return balance;
}

