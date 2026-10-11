#include <iostream>
#include "bank_account.hpp"
using namespace std;

int main()
{
    BankAccount ba(0);
    ba.deposit(1000);
    ba.withdraw(100);
    cout << "The final Balance : " << ba.getBalance() << '\n';
    return 0;
}