#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  string userInput {};
  getline (cin, userInput);

  int inputSize = userInput.size();

  for (int i = 0; i < inputSize; ++i)
  {
    for (int j = -inputSize + 1; j < inputSize; ++j)
    {
      int aux {i - abs(j)};
      if (aux < 0)
      {
        cout << " ";
        continue;
      }

      cout << userInput.at(aux);
    }

    cout << endl;
  }

  cout << endl;
  return 0;
}