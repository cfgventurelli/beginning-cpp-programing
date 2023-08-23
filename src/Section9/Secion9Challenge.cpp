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