#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include <string>
#include "Account.h"

class CheckingAccount final: public Account
{
  private:
    static constexpr const char *DEFAULT_NAME {"An Checking Account"};

    double fee;

  public:
    // Constants
    static constexpr double DEFAULT_FEE {1.5};

    // Constructors / Destructor
    CheckingAccount(std::string name = DEFAULT_NAME, double balance = Account::DEFAULT_BALANCE, double fee = DEFAULT_FEE);
    virtual ~CheckingAccount() = default;

    // Getters
    double get_fee() const;

    // General
    virtual void deposit(double amount) override;
    virtual void withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
};

#endif
