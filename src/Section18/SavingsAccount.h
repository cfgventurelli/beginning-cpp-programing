#ifndef _SAVING_ACCOUNT_H_
#define _SAVING_ACCOUNT_H_

#include <string>
#include "Account.h"

class SavingsAccount final: public Account
{
  private:
    static constexpr const char *DEFAULT_NAME {"An Savings Account"};

    double interest_rate;

  public:
    // Constants
    static constexpr double DEFAULT_INTEREST_RATE {0.0};

    // Constructors / Destructor
    SavingsAccount(std::string name = DEFAULT_NAME, double balance = Account::DEFAULT_BALANCE, double interest_rate = DEFAULT_INTEREST_RATE);
    virtual ~SavingsAccount() = default;

    // Getters
    double get_interest_rate() const;

    // General
    virtual void deposit(double amount) override;
    virtual void withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
};

#endif