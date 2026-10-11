#ifndef _BANK_ACCOUNT_HPP
#define _BANK_ACCOUNT_HPP
// #pragma once
class BankAccount
{
private:
    double balance;
public:
    BankAccount(double balance = 0);
    void deposit(double plus = 0);
    void withdraw(double mins = 0);
    double getBalance();
};
#endif 