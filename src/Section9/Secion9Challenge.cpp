/*
Section 9 Challenge
===================

This challenge is about using a collection (list) of integers and allowing the user
to select options from a menu to perform operations on the list.

Your program should display a menu options to the user as follows:
  P - Print numbers
  A - Add a number
  M - Display mean of the numbers
  S - Display the smallest number
  L - Display the largest number
  Q - Quit

Enter your choice:

The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!
*/


#include <iostream>
#include <cctype>
#include <vector>
#include <climits>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::toupper;
using std::vector;
using std::string;

int main ()
{
  bool quit {false};
  vector <int> vectorOfNumbers {};
  int smallestNumber {INT_MAX};
  int largestNumber {INT_MIN};
  int total {0};

  while (!quit)
  {
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallets number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << endl;
    cout << "Enter your choice: ";

    char optionSelected {};
    cin >> optionSelected;

    switch (toupper(optionSelected))
    {
      case 'P':
        if (vectorOfNumbers.size() == 0)
        {
          cout << "[] - the list is empty" << endl;
          break;
        }

        cout << "[ ";

        for (auto number : vectorOfNumbers) {
           cout << number << ' ';
        }
        cout << "]" << endl;

        break;
      case 'A':
      {
        cout << "Enter an integer to add to the list: ";

        int value {0};
        cin >> value;

        vectorOfNumbers.push_back(value);
        cout << value << " added" << endl;

        if (value < smallestNumber) smallestNumber = value;
        if (value > largestNumber) largestNumber = value;
        total += value;

        break;
      }
      case 'M':
        if (vectorOfNumbers.size() == 0)
        {
          cout << "Unable to calculate the mean - the list is empty" << endl;
          break;
        }

        cout << "The mean is: " << static_cast<double>(total) / vectorOfNumbers.size() << endl;
        break;
      case 'S':
        if (vectorOfNumbers.size() == 0)
        {
          cout << "Unable to determine the smallest number - the list is empty" << endl;
          break;
        }

        cout << "The smallets number is: " << smallestNumber << endl;
        break;
      case 'L':
        if (vectorOfNumbers.size() == 0)
        {
          cout << "Unable to determine the largest number - the list is empty" << endl;
          break;
        }

        cout << "The largest number is: " << largestNumber << endl;
        break;
      case 'Q':
        cout << "Goodbye!" << endl;
        quit = true;
        break;
      default:
        cout << "Unknown selection, please try again." << endl;
        break;
    }

    cout << endl;
  }

  return 0;
}