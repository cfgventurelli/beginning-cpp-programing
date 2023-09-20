#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include <iostream>
#include <string>
#include "Account.h"

class TrustAccount final: public Account
{
  private:
    static constexpr const char *DEFAULT_NAME {"An Trust Account"};

    double interest_rate;
    int withdrawals_count;

  public:
    // Constants
    static constexpr double DEFAULT_INTEREST_RATE {0.0};
    static constexpr double MAX_WITHDRAW_PERCENT {20.0};
    static constexpr short MAX_WITHDRAWALS {3};
    static constexpr double BONUS_THRESHOLD {5000.0};
    static constexpr double BONUS_VALUE {50.0};

    // Constructors / Destructor
    TrustAccount(std::string name = DEFAULT_NAME, double balance = Account::DEFAULT_BALANCE, double interest_rate = DEFAULT_INTEREST_RATE);
    virtual ~TrustAccount() = default;

    // Getters
    double get_interest_rate() const;
    double get_withdrawals_count() const;

    // General
    virtual void deposit(double amount) override;
    virtual void withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
};

#endif
