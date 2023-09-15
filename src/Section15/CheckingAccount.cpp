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
void CheckingAccount::withdraw(double amount)
{
  Account::withdraw(amount + this->fee);
}

/*****************************************************************************/
// Friends
/*****************************************************************************/
std::ostream &operator<<(std::ostream &os, const CheckingAccount &ca)
{
  os << "[Account: " << ca.get_name() << "; Balance: " << ca.get_balance() << "; Fee: " << ca.get_fee() << "]";
  return os;
}