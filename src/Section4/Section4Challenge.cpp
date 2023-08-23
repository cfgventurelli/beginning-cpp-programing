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