#include <iostream>
#include <string>
#include "TrustAccount.h"
#include "withdraw_limit_exception.h"

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
    throw withdraw_limit_exception();

  double max_withdraw_percent {(this->MAX_WITHDRAW_PERCENT / 100)};

  Account::withdraw(amount);

  ++this->withdrawals_count;
}

void TrustAccount::print(std::ostream &os) const
{
  os << "[Trust Account: " << this->get_name()
     << "; Balance: " << this->get_balance()
     << "; Interest Rate: " << this->get_interest_rate()
     << "%; Withdrawals done: " << this->get_withdrawals_count() << "]";
}