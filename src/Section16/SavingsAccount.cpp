#include <iostream>
#include <string>
#include "SavingsAccount.h"

/*****************************************************************************/
// Constructors / Destructor
/*****************************************************************************/
SavingsAccount::SavingsAccount(std::string name, double balance, double interest_rate)
  : Account(name, balance), interest_rate {interest_rate}
{
  return;
}

/*****************************************************************************/
// Getters
/*****************************************************************************/
double SavingsAccount::get_interest_rate() const
{
  return this->interest_rate;
}

/*****************************************************************************/
// General
/*****************************************************************************/
void SavingsAccount::deposit(double amount)
{
  amount *= 1 + this->get_interest_rate() / 100;

  Account::deposit(amount);
}

void SavingsAccount::withdraw(double amount)
{
  Account::withdraw(amount);
}

void SavingsAccount::print(std::ostream &os) const
{
  os << "[Savings Account: " << this->get_name()
     << "; Balance: " << this->get_balance()
     << "; Interest Rate: " << this->get_interest_rate() << "%]";
}
