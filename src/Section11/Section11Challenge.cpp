/*
Section 11 Challenge
====================

Recall the challenge from Section 9 below.

Your challenge for section 11 is to modularize your solution to the Section 9
challenge by refactoring your solution so that it uses uses functions.

You decide how to modularize the program.
you can use my solution which is included in this file, or modularize your solution.

Here are a few hints:
  - Create functions for each major function
  - Keep the functions small
  - Remember the Boss/Worker analogy
  - Keep the vector declaration in the main function and pass the vector object
    to any function that requires it

  DO NOT move the vector object outside main and make it a global variable.

  - You can start by defining a function that displays the menu
  - You can then define a function that reads the selection from the user and returns it in uppercase
  - Create functions for each menu option
  - Create functions that display the list of numbers, calculates the mean and so forth

Take it one function at a time and take your time.

If you get frustrated, take a break -- this isn't as easy as it looks the first time you do it!

Finally, don't forget to use function prototypes!

Good luck -- I know you can do it!
*/

#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::toupper;
using std::vector;
using std::string;

/******************************************************************************
 * Prototypes
******************************************************************************/
void displayMenu();
char getSelection();
void handleDisplayNumbers(const vector<int> &vectorOfNumbers);
void handleAddNumber(vector<int> &vectorOfNumbers);
void handleDisplayMean(const vector<int> &vectorOfNumbers);
void handleDisplaySmallest(const vector<int> &vectorOfNumbers);
void handleDisplayLargest(const vector<int> &vectorOfNumbers);
void handleQuit();
void handlUnknownSelection();
void displayNumbers(const vector<int> &vectorOfNumbers);
double getMean(const vector<int> &vectorOfNumbers);
int getSmallest(const vector<int> &vectorOfNumbers);
int getLargest(const vector<int> &vectorOfNumbers);

/******************************************************************************
 * Main function of the program
******************************************************************************/
int main ()
{
  vector <int> vectorOfNumbers {};
  char userSelection {};

  do
  {
    displayMenu();

    userSelection = getSelection();

    switch (userSelection)
    {
      case 'P':
        handleDisplayNumbers(vectorOfNumbers);
        break;
      case 'A':
        handleAddNumber(vectorOfNumbers);
        break;
      case 'M':
        handleDisplayMean(vectorOfNumbers);
        break;
      case 'S':
        handleDisplaySmallest(vectorOfNumbers);
        break;
      case 'L':
        handleDisplayLargest(vectorOfNumbers);
        break;
      case 'Q':
        handleQuit();
        break;
      default:
        handlUnknownSelection();
    }

    cout << endl;
  } while (userSelection != 'Q');

  return 0;
}

/******************************************************************************
 * Display a menu with all the choices available for the user to chose
******************************************************************************/
void displayMenu()
{
  cout << "P - Print numbers" << endl;
  cout << "A - Add a number" << endl;
  cout << "M - Display mean of the numbers" << endl;
  cout << "S - Display the smallest number" << endl;
  cout << "L - Display the largest number" << endl;
  cout << "Q - Quit" << endl;
  cout << endl;
}

/******************************************************************************
 * Return the user's choice
******************************************************************************/
char getSelection() {
  cout << "Enter your choice: ";

  char userChoice {};
  cin >> userChoice;

  return toupper(userChoice);
}

/******************************************************************************
 * Display all numbers contained in the vector
******************************************************************************/
void handleDisplayNumbers(const vector<int> &vectorOfNumbers)
{
  if (vectorOfNumbers.size() == 0)
  {
    cout << "[] - the list is empty" << endl;
    return;
  }

  displayNumbers(vectorOfNumbers);
}

/******************************************************************************
 * Add a new number to the vector
******************************************************************************/
void handleAddNumber(vector<int> &vectorOfNumbers)
{
  cout << "Enter an integer to add to the list: ";

  int value {0};
  cin >> value;

  vectorOfNumbers.push_back(value);
  cout << value << " added" << endl;
}

/******************************************************************************
 * Display the mean
******************************************************************************/
void handleDisplayMean(const vector<int> &vectorOfNumbers)
{
  if (vectorOfNumbers.size() == 0)
  {
    cout << "Unable to calculate the mean - the list is empty" << endl;
    return;
  }

  cout << "The mean is: " << getMean(vectorOfNumbers) << endl;
}

/******************************************************************************
 * Display the smallest number in the vector
******************************************************************************/
void handleDisplaySmallest(const vector<int> &vectorOfNumbers)
{
  if (vectorOfNumbers.size() == 0)
  {
    cout << "Unable to determine the smallest number - the list is empty" << endl;
    return;
  }

  cout << "The smallest number is: " << getSmallest(vectorOfNumbers) << endl;
}

/******************************************************************************
 * Display the largest number in the vector
******************************************************************************/
void handleDisplayLargest(const vector<int> &vectorOfNumbers)
{
  if (vectorOfNumbers.size() == 0)
  {
    cout << "Unable to determine the largest number - the list is empty" << endl;
    return;
  }

  cout << "The largest number is: " << getLargest(vectorOfNumbers) << endl;
}

/******************************************************************************
 * Display the goodbye message
******************************************************************************/
void handleQuit()
{
  cout << "Goodbye!" << endl;
}

/******************************************************************************
 * Display the unknown selection message
******************************************************************************/
void handlUnknownSelection()
{
  cout << "Unknown selection, please try again." << endl;
}

/******************************************************************************
 * Display all numbers in the vector
******************************************************************************/
void displayNumbers(const vector<int> &vectorOfNumbers)
{
  cout << "[ ";
  for (auto number : vectorOfNumbers) {
      cout << number << ' ';
  }
  cout << "]" << endl;
}

/******************************************************************************
 * Return the mean of the vector
******************************************************************************/
double getMean(const vector<int> &vectorOfNumbers)
{
  double total {0.0};
  for (auto n : vectorOfNumbers)
    total += n;

  return total / vectorOfNumbers.size();
}

/******************************************************************************
 * Return the smallest number in the vector
******************************************************************************/
int getSmallest(const vector<int> &vectorOfNumbers)
{
  int smallestNumber = vectorOfNumbers.at(0);
  for (size_t i = 1; i < vectorOfNumbers.size(); ++i)
    if (vectorOfNumbers.at(i) < smallestNumber)
      smallestNumber = vectorOfNumbers.at(i);

  return smallestNumber;
}

/******************************************************************************
 * Return the largest number in the vector
******************************************************************************/
int getLargest(const vector<int> &vectorOfNumbers)
{
  int largestNumber = vectorOfNumbers.at(0);
  for (size_t i = 1; i < vectorOfNumbers.size(); ++i)
    if (vectorOfNumbers.at(i) > largestNumber)
      largestNumber = vectorOfNumbers.at(i);

  return largestNumber;
}
