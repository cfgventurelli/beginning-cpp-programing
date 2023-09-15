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

/*****************************************************************************/
// Friends
/*****************************************************************************/
std::ostream &operator<<(std::ostream &os, const SavingsAccount &sa)
{
  os << "[Account: " << sa.get_name() << "; Balance: " << sa.get_balance() << "; Interest Rate: " << sa.get_interest_rate() << "%]";
  return os;
}