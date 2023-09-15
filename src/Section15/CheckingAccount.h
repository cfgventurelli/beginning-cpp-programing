#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include <string>
#include "Account.h"

class CheckingAccount: public Account
{
  friend std::ostream &operator<<(std::ostream &os, const CheckingAccount &ca);

  private:
    static constexpr const char *DEFAULT_NAME {"An Checking Account"};

    double fee;

  public:
    // Constants
    static constexpr double DEFAULT_FEE {1.5};

    // Constructors / Destructor
    CheckingAccount(std::string name = DEFAULT_NAME, double balance = Account::DEFAULT_BALANCE, double fee = DEFAULT_FEE);

    // Getters
    double get_fee() const;

    // General
    void withdraw(double amount);
};

#endif
