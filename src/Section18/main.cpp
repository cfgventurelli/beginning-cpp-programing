/*
Section 18 Challenge
====================

For this challenge we want to integrate our own user-defined exception classes into the Account class
hierarchy.

The account classes are provided for you.
Also, the IllegalBalanceException.h file contains the declaration for the IllegalBalanceException class.

What I would like you to do is:
1. Derive IllegalBalanceException from i_exception and implement the what() method to provide an exception message.
   This exception object should be thrown from the Account class constructor if an account object is created with a negative 
   balance.

2. Derive InsufficentFundsException from i_exception and implement the what() method to provide an exception message.
   This exception object should be thrown if a withdraw results in a negative balance.
   You should throw this exception object from the Account withdraw method.

That's it - good luck!
Test your code in the main driver.

Have fun and experiment!
*/

#include <iostream>
#include <vector>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "i_exception.h"

using std::cout;
using std::cerr;
using std::endl;

int main()
{
  cout << "=== Negative balance ===========================================================" << endl;
  try
  {
    auto sa {SavingsAccount("Savings Account", -10)};
  }
  catch (const i_exception &e)
  {
    cerr << e << endl;
  }
  cout << endl;

  cout << "=== Negative deposit ===========================================================" << endl;
  try
  {
    auto ca {CheckingAccount("Checking Account", 0)};
    ca.deposit(-10);
  }
  catch(const i_exception &e)
  {
    cerr << e << endl;
  }
  cout << endl;

  cout << "=== Negative withdraw ==========================================================" << endl;
  try
  {
    auto ca {TrustAccount("Trust Account", 0)};
    ca.withdraw(-10);
  }
  catch(const i_exception &e)
  {
    cerr << e << endl;
  }
  cout << endl;

  cout << "=== Insuficient funds ==========================================================" << endl;
  try
  {
    auto sa {SavingsAccount("Savings Account", 1000)};
    sa.withdraw(1000.1);
  }
  catch (const i_exception &e)
  {
    cerr << e << endl;
  }
  cout << endl;

  return 0;
}
