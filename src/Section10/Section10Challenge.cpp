#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  string alphabet {};
  string key {};

  for (char c = 'A'; c <= 'Z'; ++c) alphabet += c;
  for (char c = 'a'; c <= 'z'; ++c) alphabet += c;

  while (key.size() < alphabet.size())
  {
    char dummy = rand() % 95 + 33;

    if (key.find(dummy) != string::npos) continue;

    key += dummy;
  }

  string userInput {};
  cout << "Enter your secret message: ";
  getline (cin, userInput);
  cout << endl;

  string encryptedMessage {};
  for (auto c : userInput)
  {
    size_t index = alphabet.find(c);
    encryptedMessage += (index == string::npos) ? c : key.at(index);
  }

  cout << "encrypted message: " << encryptedMessage << endl << endl;

  string decryptedMessage {};
  for (auto c : encryptedMessage)
  {
    size_t index = key.find(c);
    decryptedMessage += (index == string::npos) ? c : alphabet.at(index);
  }

  cout << "Deencrypted message: " << decryptedMessage << endl << endl;

  return 0;
}