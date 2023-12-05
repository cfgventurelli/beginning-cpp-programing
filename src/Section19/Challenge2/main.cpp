/*
Section 19 Challenge
====================

Challenge 2

Automated Grader

Write a program that reads a file named 'responses.txt" that contains the answer key for a quiz
as well as student responses for the quiz.

The answer key is the first item in the file.
Student1 name
Student1 responses
Student2 name
Student2 responses
...

Here is a sample file.

ABCDE
Frank
ABCDE
Larry
ABCAC
Moe
BBCDE
Curly
BBAAE
Michael
BBCDE

You should read the file and display:
Each student's name and score (#correct out of 5)
At the end, the class average should be displayed
You may assume that the data in the file is properly formatted

Program should output to the console the following:
Student                Score
----------------------------
Frank                      5
Larry                      3
Moe                        4
Curly                      2
Michael                    4
----------------------------
Average score            3.6
*/

#include <iostream>
#include <iomanip>
#include <fstream>

const int FIRST_COLUMN{20};
const int SECOND_COLUMN{5};

int process_response(const std::string &response, const std::string &answer_key);
void print_header();
void print_footer(float average_score);
void print_student(const std::string &name, int score);

int main()
{
  std::ifstream file;
  file.open("./responses.txt");

  if (!file)
  {
    std::cerr << "Problem opening file" << std::endl;
    return -1;
  }

  std::string answer_key;
  std::string student;
  std::string response;
  int total_students{0};
  int total_score{0};

  print_header();

  file >> answer_key;

  while (file >> student >> response)
  {
    ++total_students;
    int score = process_response(response, answer_key);
    total_score += score;
    print_student(student, score);
  }

  file.close();

  print_footer(static_cast<float>(total_score) / total_students);
  std::cout << std::endl;

  return 0;
}

int process_response(const std::string &response, const std::string &answer_key)
{
  int score{0};

  for (size_t j{0}; j < answer_key.size(); ++j)
  {
    score += (answer_key[j] == response[j]);
  }

  return score;
}

void print_line()
{
  std::cout << std::setfill('-');
  std::cout << std::setw(25) << "-" << std::endl;
  std::cout << std::setfill(' ');
}

void print_header()
{
  std::cout << std::setprecision(1) << std::fixed;
  std::cout << std::setw(FIRST_COLUMN) << std::left << "Student"
            << std::setw(SECOND_COLUMN) << std::right << "Score" << std::endl;
  print_line();
}

void print_footer(float average_score)
{
  print_line();
  std::cout << std::setw(FIRST_COLUMN) << std::left << "Average score"
            << std::setw(SECOND_COLUMN) << std::right << average_score << std::endl;
}

void print_student(const std::string &name, int score)
{
  std::cout << std::setw(FIRST_COLUMN) << std::left << name
            << std::setw(SECOND_COLUMN) << std::right << score << std::endl;
}
