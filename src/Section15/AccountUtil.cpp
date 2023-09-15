#include <iostream>
#include <vector>
#include "AccountUtil.h"

/*****************************************************************************/
// Account
/*****************************************************************************/
void display(const std::vector<Account> &accounts)
{
  for (const Account &a : accounts)
    std::cout << a << std::endl;
}

void deposit(std::vector<Account> &accounts, double amount)
{
  for (Account &a : accounts)
  {
    std::cout << "Depositing " << amount << " to " << a << std::endl;
    a.deposit(amount);
  }
}

void withdraw(std::vector<Account> &accounts, double amount)
{
  for (Account &a : accounts)
  {
    std::cout << "Withdrawing " << amount << " from " << a << std::endl;
    a.withdraw(amount);
  }
}

/*****************************************************************************/
// Savings Account
/*****************************************************************************/
void display(const std::vector<SavingsAccount> &savings_accounts)
{
  for (const SavingsAccount &sa : savings_accounts)
    std::cout << sa << std::endl;
}

void deposit(std::vector<SavingsAccount> &savings_accounts, double amount)
{
  for (SavingsAccount &sa : savings_accounts)
  {
    std::cout << "Depositing " << amount << " to " << sa << std::endl;
    sa.deposit(amount);
  }
}

void withdraw(std::vector<SavingsAccount> &savings_accounts, double amount)
{
  for (SavingsAccount &sa : savings_accounts)
  {
    std::cout << "Withdrawing " << amount << " from " << sa << std::endl;
    sa.withdraw(amount);
  }
}

/*****************************************************************************/
// Checking Account
/*****************************************************************************/
void display(const std::vector<CheckingAccount> &checking_accounts)
{
  for (const CheckingAccount &ca : checking_accounts)
    std::cout << ca << std::endl;
}

void deposit(std::vector<CheckingAccount> &checking_accounts, double amount)
{
  for (CheckingAccount &ca : checking_accounts)
  {
    std::cout << "Depositing " << amount << " to " << ca << std::endl;
    ca.deposit(amount);
  }
}

void withdraw(std::vector<CheckingAccount> &checking_accounts, double amount)
{
  for (CheckingAccount &ca : checking_accounts)
  {
    std::cout << "Withdrawing " << amount << " from " << ca << std::endl;
    ca.withdraw(amount);
  }
}

/*****************************************************************************/
// Trust Account
/*****************************************************************************/
void display(const std::vector<TrustAccount> &trust_accounts)
{
  for (const TrustAccount &ta : trust_accounts)
    std::cout << ta << std::endl;
}

void deposit(std::vector<TrustAccount> &trust_accounts, double amount)
{
  for (TrustAccount &ta : trust_accounts)
  {
    std::cout << "Depositing " << amount << " to " << ta << std::endl;
    ta.deposit(amount);
  }
}

void withdraw(std::vector<TrustAccount> &trust_accounts, double amount)
{
  for (TrustAccount &ta : trust_accounts)
  {
    std::cout << "Withdrawing " << amount << " from " << ta << std::endl;
    ta.withdraw(amount);
  }
}
