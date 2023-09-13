#include <cstring>
#include <iostream>
#include "MyString.h"

/*****************************************************************************/
// Constructors / Destructor
/*****************************************************************************/
MyString::MyString(const char *str)
{
  if (!str)
  {
    this->str = new char[1];
    *(this->str) = '\0';
    return;
  }

  this->str = new char [std::strlen(str) + 1];
  std::strcpy(this->str, str);
}

/*****************************************************************************/
MyString::MyString(const MyString &ms)
  : MyString(ms.str)
{
  return;
}

/*****************************************************************************/
MyString::MyString(MyString &&ms)
  : str {ms.str}
{
  ms.str = nullptr;
}

/*****************************************************************************/
MyString::~MyString()
{
  delete [] this->str;
}

/*****************************************************************************/
// Operations
/*****************************************************************************/
MyString &MyString::operator=(const MyString &ms)
{
  if (this == &ms)
    return *this;

  std::strcpy(this->str, ms.str);

  return *this;
}

/*****************************************************************************/
MyString &MyString::operator=(MyString &&ms)
{
  if (this == &ms)
    return *this;

  this->str = ms.str;

  ms.str = nullptr;
  return *this;
}

/*****************************************************************************/
MyString MyString::operator+(const MyString &ms) const
{
  char *buff = new char [this->length() + ms.length() + 1];
  std::strcpy(buff, this->str);
  std::strcat(buff, ms.str);

  MyString temp {buff};

  delete [] buff;

  return temp;
}

/*****************************************************************************/
MyString MyString::operator-(const MyString &ms) const
{
  char *p = std::strstr(this->str, ms.str);

  if (!p)
    return *this;

  char *buff = new char [(this->length() - ms.length()) + 1];
  size_t from = p - this->str;
  size_t to = from + ms.length() - 1;

  size_t idx {0};
  for (size_t i {0}; i < this->length(); ++i)
  {
    if (i >= from && i <= to)
      continue;

    buff[idx++] = this->str[i];
  }

  MyString temp {buff};

  delete [] buff;

  return temp;
}

/*****************************************************************************/
MyString MyString::operator*(const int value) const
{
  char *buff = new char [this->length() * value + 1];
  std::strcpy(buff, this->str);

  for (size_t i {0}; i < value -1; ++i)
    std::strcat(buff, this->str);

  MyString temp {buff};

  delete [] buff;

  return temp;
}

/*****************************************************************************/
MyString MyString::operator/(const int value) const
{
  int size = this->length() / value;
  char *buff = new char [size + 1];

  for (size_t i {0}; i < size; ++i)
    buff[i] = this->str[i];

  buff[size] = '\0';

  MyString temp {buff};

  delete [] buff;

  return temp;
}

/*****************************************************************************/
MyString &MyString::operator+=(const MyString &ms)
{
  *this = *this + ms;

  return *this;
}

/*****************************************************************************/
MyString &MyString::operator-=(const MyString &ms)
{
  *this = *this - ms;

  return *this;
}

/*****************************************************************************/
MyString &MyString::operator*=(const int value)
{
  *this = *this * value;

  return *this;
}

/*****************************************************************************/
MyString &MyString::operator/=(const int value)
{
  *this = *this / value;

  return *this;
}

/*****************************************************************************/
MyString MyString::operator-() const
{
  char *buff = new char [this->length() + 1];

  size_t i {0};
  while (this->str[i] != '\0')
  {
    buff[i] = (std::islower(this->str[i]) ? std::toupper(this->str[i]) : std::tolower(this->str[i]));
    ++i;
  }

  MyString temp {buff};

  delete [] buff;

  return temp;
}

/*****************************************************************************/
MyString &MyString::operator++()
{
  int len = this->length();

  char *temp = new char [len + 2];
  std::strcpy(temp, this->str);

  temp[len] = 'X';

  this->str = temp;

  temp = nullptr;

  return *this;
}

/*****************************************************************************/
MyString MyString::operator++(int)
{
  MyString temp {*this};

  this->operator++();

  return temp;
}

/*****************************************************************************/
MyString &MyString::operator--()
{
  int len = this->length();

  if (len == 0)
    return *this;

  char *temp = new char [len];

  for (size_t i {0}; i < len - 1; ++i)
    temp[i] = this->str[i];

  this->str = temp;

  temp = nullptr;

  return *this;
}

/*****************************************************************************/
MyString MyString::operator--(int)
{
  MyString temp {*this};

  this->operator--();

  return temp;
}

/*****************************************************************************/
bool MyString::operator==(const MyString &ms) const
{
  return std::strcmp(this->str, ms.str) == 0;
}

/*****************************************************************************/
bool MyString::operator!=(const MyString &ms) const
{
  return !this->operator==(ms);
}

/*****************************************************************************/
bool MyString::operator>(const MyString &ms) const
{
  return std::strcmp(this->str, ms.str) > 0;
}

/*****************************************************************************/
bool MyString::operator<(const MyString &ms) const
{
  return std::strcmp(this->str, ms.str) < 0;
}

/*****************************************************************************/
bool MyString::operator>=(const MyString &ms) const
{
  return this->operator>(ms) || this->operator==(ms);
}

/*****************************************************************************/
bool MyString::operator<=(const MyString &ms) const
{
  return this->operator<(ms) || this->operator==(ms);
}

/*****************************************************************************/
// Getters
/*****************************************************************************/
int MyString::length() const
{
  return std::strlen(this->str);
}

/*****************************************************************************/
const char *MyString::get_str() const
{
  return this->str;
}

/*****************************************************************************/
// Friends
/*****************************************************************************/
std::ostream &operator<<(std::ostream &cout, const MyString &ms)
{
  cout << ms.get_str();
  return cout;
}

/*****************************************************************************/
std::istream &operator>>(std::istream &cin, MyString &ms)
{
  char *buff {new char [1000]};
  cin >> buff;

  ms = MyString {buff};

  delete [] buff;

  return cin;
}
