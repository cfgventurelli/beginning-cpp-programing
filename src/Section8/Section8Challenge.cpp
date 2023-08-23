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