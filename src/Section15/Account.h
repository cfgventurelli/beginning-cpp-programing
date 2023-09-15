#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account
{
  friend std::ostream &operator<<(std::ostream &os, const Account &a);

  private:
    static constexpr const char *DEFAULT_NAME {"An Account"};

    std::string name;
    double balance;

  protected:
    static constexpr double DEFAULT_BALANCE {0.0};

  public:
    // Constructors / Destructor
    Account(std::string name = DEFAULT_NAME, double balance = DEFAULT_BALANCE);

    // Getters
    std::string get_name() const;
    double get_balance() const;

    // General
    void deposit(double amount);
    void withdraw(double amount);
};

#endif
