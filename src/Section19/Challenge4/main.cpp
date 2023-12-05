/*
Section 19 Challenge
====================

Challenge 4

Copy Romeo and Juliet with line numbers

This challenge should be pretty easy.
I have provided the text to Romeo and Juliet in a file named romeoandjuliet.txt

For this challenge you have to make copy of the Romeo and Juliet file and save it to another file.
This new copy should have line numbers at the beginning of each line in the play.
Please format the numbers nicely so everything lines up.

Feel free to extend this challenge in any way you like.
For example, you may want to provide line numbers only for lines that actually have text

Have fun!
*/

#include <iostream>
#include <iomanip>
#include <fstream>

int main()
{
  std::ifstream in_file;

  in_file.open("./romeoandjuliet.txt");
  if (!in_file)
  {
    std::cerr << "Problem opening file" << std::endl;
    return -1;
  }

  std::ofstream out_file;

  out_file.open("./romeoandjuliet_copy.txt");
  if (!out_file)
  {
    std::cerr << "Problem creating/opening file" << std::endl;
    return -1;
  }

  std::string line{};
  int row_number{0};
  while (std::getline(in_file, line))
  {
    ++row_number;
    if (line != "")
    {
      out_file << std::setw(7) << std::left;
    }
    out_file << row_number << line << std::endl;
  }

  out_file.close();
  in_file.close();

  std::cout << "Copy complete" << std::endl;

  return 0;
}