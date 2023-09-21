/*
Section 8 Challenge
===================

For this program I will be using US dollars and cents.

Write a program that asks the user to enter the following:
An integer representing the number of cents 

You may assume that the number of cents entered is greater than or equal to zero

The program should then display how to provide that change to the user.

In the US:
  1 dollar is 100 cents
  1 quarter is 25 cents
  1 dime is 10 cents
  1 nickel is 5 cents, and
  1 penny is 1 cent.

Here is a sample run:

Enter an amount in cents: 92

You can provide this change as follows:
dollars  => 0
quarters => 3
dimes    => 1
nickels  => 1
pennies  => 2

Feel free to use your own currency system.
Also, think of how you might solve the problem using the modulo operator.

Have fun and test your program!!
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  const int DOLLAR_VALUE {100};
  const int QUARTER_VALUE {25};
  const int DIME_VALUE {10};
  const int NICKEL_VALUE {5};

  cout << "Enter an amount in cents: ";
  int balance {0};
  cin >> balance;

  cout << "You can provide change for this change as follow: " << endl;

  int dollars {balance / DOLLAR_VALUE};
  balance %= DOLLAR_VALUE;

  int quarters {balance / QUARTER_VALUE};
  balance %= QUARTER_VALUE;

  int dimes {balance / DIME_VALUE};
  balance %= DIME_VALUE;

  int nickels {balance / NICKEL_VALUE};
  balance %= NICKEL_VALUE;

  int pennies {balance};

  cout << "dollars  => " << dollars << endl;
  cout << "quarters => " << quarters << endl;
  cout << "dimes    => " << dimes << endl;
  cout << "nickels  => " << nickels << endl;
  cout << "pennies  => " << pennies << endl;

  return 0;
}