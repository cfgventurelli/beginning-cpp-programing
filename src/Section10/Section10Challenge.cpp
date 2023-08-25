/*
Section 10 Challenge
====================

Substitution Cipher

A simple and very old method of sending secret messages is the substitution cipher.
You might have used this cipher with your friends when you were a kid.
Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

Write a program thats ask a user to enter a secret message.

Encrypt this message using the substitution cipher and display the encrypted message.
Then decryped the encrypted message back to the original message.

You may use the 2 strings below for  your subsitition.
For example, to encrypt you can replace the character at position n in alphabet 
with the character at position n in key.

To decrypt you can replace the character at position n in key
with the character at position n in alphabet.

Have fun! And make the cipher stronger if you wish!
Currently the cipher only substitutes letters - you could easily add digits, puncuation, whitespace and so
forth. Also, currently the cipher always substitues a lowercase letter with an uppercase letter and vice-versa.
This could also be improved.

Remember, the less code you write the less code you have to test!
Reuse existing functionality in libraries and in the std::string class!
*/

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