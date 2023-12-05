/*
Section 19 Challenge
====================

Challenge 3

Word finder

Ask the user to enter a word
Process the Romeo and Juliet file and determine how many total words there are
and how many times the word the user entered appears as a substring of a word in the play.

For example.
If the user enters: love
Then the words love, lovely, and beloved will all be considered matches.
You decide whether you want to be case sensitive or not. My solution is case sensitive

Sample are some sample runs:

Enter the substring to search for: love
25919 words were searched...
The substring love was found 171 times

Enter the substring to search for: Romeo
25919 words were searched...
The substring Romeo was found 132 times

Enter the substring to search for: Juliet
25919 words were searched...
The substring Juliet was found 49 times

Enter the substring to search for: Frank
25919 words were searched...
The substring Frank was found 0 times

Have fun!
*/

#include <iostream>
#include <fstream>

int main()
{
  std::ifstream file;
  file.open("./romeoandjuliet.txt");

  if (!file)
  {
    std::cerr << "Problem opening file" << std::endl;
    return -1;
  }

  int words_counter{0};
  int match_counter{0};
  std::string word;
  std::string word_to_find;

  std::cout << "Enter the substring to seach for: ";
  std::cin >> word_to_find;

  while (file >> word)
  {
    ++words_counter;
    match_counter += (word.find(word_to_find) != std::string::npos);
  }

  file.close();

  std::cout << words_counter << " words were seached..." << std::endl;
  std::cout << "The substring '" << word_to_find << "' was found " << match_counter << " times" << std::endl;
  std::cout << std::endl;

  return 0;
}
