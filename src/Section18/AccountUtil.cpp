#include <iostream>
#include <vector>
#include "AccountUtil.h"

void display(const std::vector<Account *> &accounts)
{
  for (const auto a : accounts)
    std::cout << *a << std::endl;
}

void deposit(std::vector<Account *> &accounts, double amount)
{
  for (auto a : accounts)
  {
    std::cout << "Depositing " << amount << " to " << *a << std::endl;
    a->deposit(amount);
  }
}

void withdraw(std::vector<Account *> &accounts, double amount)
{
  for (auto a : accounts)
  {
    std::cout << "Withdrawing " << amount << " from " << *a << std::endl;
    a->withdraw(amount);
  }
}

void delete_accounts(std::vector<Account *> &accounts)
{
  for (auto a : accounts)
  {
    std::cout << "Deleting " << *a << std::endl;
    delete a;
  }

  accounts.clear();
}