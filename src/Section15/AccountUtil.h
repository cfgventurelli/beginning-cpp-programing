#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"

void display(const std::vector<Account> &accounts);
void deposit(std::vector<Account> &accounts, double amount);
void withdraw(std::vector<Account> &accounts, double amount);

void display(const std::vector<SavingsAccount> &savings_accounts);
void deposit(std::vector<SavingsAccount> &savings_accounts, double amount);
void withdraw(std::vector<SavingsAccount> &savings_accounts, double amount);

void display(const std::vector<CheckingAccount> &checking_accounts);
void deposit(std::vector<CheckingAccount> &checking_accounts, double amount);
void withdraw(std::vector<CheckingAccount> &checking_accounts, double amount);

void display(const std::vector<TrustAccount> &trust_accounts);
void deposit(std::vector<TrustAccount> &trust_accounts, double amount);
void withdraw(std::vector<TrustAccount> &trust_accounts, double amount);