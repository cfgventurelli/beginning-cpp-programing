#include <iostream>
#include <string>
#include "Account.h"
#include "illegal_balance_exception.h"
#include "insufficent_funds_exception.h"
#include "invalid_amount_exception.h"

/*****************************************************************************/
// Constructors / Destructor
/*****************************************************************************/
Account::Account(std::string name, double balance)
  : name {name}, balance {balance}
{
  if (this->balance < 0.0)
    throw illegal_balance_exception();
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
    throw invalid_amount_exception();

  this->balance += amount;
}

void Account::withdraw(double amount)
{
  if (amount <= 0)
    throw invalid_amount_exception();

  if (amount > this->balance)
    throw insufficent_funds_exception();

  this->balance -= amount;
}
