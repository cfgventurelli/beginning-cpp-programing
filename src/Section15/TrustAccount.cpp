#include <iostream>
#include <string>
#include "TrustAccount.h"

/*****************************************************************************/
// Constructors / Destructor
/*****************************************************************************/
TrustAccount::TrustAccount(std::string name, double balance, double interest_rate)
  : Account(name, balance), interest_rate {interest_rate}, withdrawals_count {0}
{
  return;
}

/*****************************************************************************/
// Getters
/*****************************************************************************/
double TrustAccount::get_interest_rate() const
{
  return this->interest_rate;
}

double TrustAccount::get_withdrawals_count() const
{
  return this->withdrawals_count;
}

/*****************************************************************************/
// General
/*****************************************************************************/
void TrustAccount::deposit(double amount)
{
  double amount_to_deposit {amount * (1 + this->get_interest_rate() / 100)};

  amount_to_deposit += amount >= this->BONUS_THRESHOLD ? this->BONUS_VALUE : 0;

  Account::deposit(amount_to_deposit);
}

void TrustAccount::withdraw(double amount)
{
  if (this->get_withdrawals_count() == this->MAX_WITHDRAWALS)
  {
    std::cout << "Withdrawal limit has been reached" << std::endl;
    return;
  }

  double max_withdraw_percent {(this->MAX_WITHDRAW_PERCENT / 100)};

  if (amount / this->get_balance() >= max_withdraw_percent)
  {
    std::cout << "The amount exceed the withdrawal limit of " << this->get_balance() * max_withdraw_percent << std::endl;
    return;
  }

  double current_balance = this->get_balance();

  Account::withdraw(amount);

  if (current_balance != this->get_balance())
    ++this->withdrawals_count;
}
/*****************************************************************************/
// Friends
/*****************************************************************************/
std::ostream &operator<<(std::ostream &os, const TrustAccount &ta)
{
  os << "[Account: " << ta.get_name()
     << "; Balance: " << ta.get_balance()
     << "; Interest Rate: " << ta.get_interest_rate()
     << "%; Withdrawals done: " << ta.get_withdrawals_count() << "]";
  return os;
}