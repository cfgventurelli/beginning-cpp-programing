#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>
#include "I_Printable.h"

class Account: public I_Printable
{
  private:
    static constexpr const char *DEFAULT_NAME {"An Account"};

    std::string name;
    double balance;

  protected:
    static constexpr double DEFAULT_BALANCE {0.0};

  public:
    // Constructors / Destructor
    Account(std::string name = DEFAULT_NAME, double balance = DEFAULT_BALANCE);
    virtual ~Account() = default;

    // Getters
    std::string get_name() const;
    double get_balance() const;

    // General
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void print(std::ostream &os) const override = 0;
};

#endif
