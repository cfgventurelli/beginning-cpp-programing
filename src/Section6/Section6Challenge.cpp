#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  const double SMALL_ROOM_PRICE = 25;
  const double LARGE_ROOM_PRICE = 35;
  const double SALES_TAX_RATE = 0.06;
  const int ESTIMATE_VALID = 30; // Days

  cout << "Hello! Welcome to Carlos' Carpet Cleaning Service" << endl << endl;

  cout << "How many small rooms would you like cleaned? ";
  int smallRooms {0};
  cin >> smallRooms;

  cout << "How many large rooms would you like cleaned? ";
  int largeRooms {0};
  cin >> largeRooms;

  double cost = (smallRooms * SMALL_ROOM_PRICE) + (largeRooms * LARGE_ROOM_PRICE);
  double taxValue = cost * SALES_TAX_RATE;

  cout << endl;
  cout << "Estimate for carpet cleaning service" << endl;
  cout << "Number of small rooms: " << smallRooms << endl;
  cout << "Number of large rooms: " << largeRooms << endl;
  cout << "Price per small room $: " << SMALL_ROOM_PRICE << endl;
  cout << "Price per large room $: " << LARGE_ROOM_PRICE << endl;
  cout << "Cost: $" << cost << endl;
  cout << "Tax: $" << taxValue << endl;
  cout << "========================================" << endl;
  cout << "Total estimate: $" << cost + taxValue << endl;
  cout << "This estimate is valid for " << ESTIMATE_VALID << " days" << endl;
  cout << endl;
}