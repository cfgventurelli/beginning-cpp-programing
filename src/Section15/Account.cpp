#include <iostream>
#include <string>
#include "Account.h"

/*****************************************************************************/
// Constructors / Destructor
/*****************************************************************************/
Account::Account(std::string name, double balance)
  : name {name}, balance {balance}
{
  return;
}

/*****************************************************************************/
// Getters
/*****************************************************************************/
std::string Account::get_name() const
{
  return this->name;
}

double Account::get_balance() const
{
  return this->balance;
}

/*****************************************************************************/
// General
/*****************************************************************************/
void Account::deposit(double amount)
{
  if (amount <= 0)
  {
    std::cout << "Invalid amount" << std::endl;
    return;
  }

  this->balance += amount;
}

void Account::withdraw(double amount)
{
  if (amount <= 0)
  {
    std::cout << "Invalid amount" << std::endl;
    return;
  }

  if (amount > this->balance)
  {
    std::cout << "Insuficient funds" << std::endl;
    return;
  }

  this->balance -= amount;
}

/*****************************************************************************/
// Friends
/*****************************************************************************/
std::ostream &operator<<(std::ostream &os, const Account &a)
{
  os << "[Account: " << a.name << "; Balance: " << a.balance << "]";
  return os;
}
