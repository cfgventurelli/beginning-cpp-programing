#include <iostream>
#include <string>
#include "CheckingAccount.h"

/*****************************************************************************/
// Constructors / Destructor
/*****************************************************************************/
CheckingAccount::CheckingAccount(std::string name, double balance, double fee)
  : Account(name, balance), fee {fee}
{
  return;
}

/*****************************************************************************/
// Getters
/*****************************************************************************/
double CheckingAccount::get_fee() const
{
  return this->fee;
}

/*****************************************************************************/
// General
/*****************************************************************************/
void CheckingAccount::deposit(double amount)
{
  Account::deposit(amount);
}

void CheckingAccount::withdraw(double amount)
{
  Account::withdraw(amount + this->fee);
}

void CheckingAccount::print(std::ostream &os) const
{
  os << "[Checking Account: " << this->get_name()
     << "; Balance: " << this->get_balance()
     << "; Fee: " << this->get_fee() << "]";
}