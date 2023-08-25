/*
Section 4 Challenge
===================

Create a C++ program that asks the user for their favorite number between 1 and 100
then read this number from the console.

Suppose the user enters 24.

Then display the following to the console:

Amazing!! That's my favorite number too!
No really!!, 24 is my favorite number!


Below are 2 sample runs of the program:
=======================================
Enter your favorite number between 1 and 100: 24
Amazing!! That's my favorite number too!
No really!!, 24 is my favorite number!


Enter your favorite number between 1 and 100: 75
Amazing!! That's my favorite number too!
No really!!, 75 is my favorite number!
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int favoriteNumber;

  cout << "Enter your favorite number between 1 and 100: ";
  cin >> favoriteNumber;

  cout << "Amazing!! That's my favorit number too!" << endl;
  cout << "No really!! " << favoriteNumber << " is my favorite number" << endl;

  return 0;
}