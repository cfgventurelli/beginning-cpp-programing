#ifndef _MY_STRING_H_
#define _MY_STRING_H_

class MyString
{
  friend std::ostream &operator<<(std::ostream &cout, const MyString &ms);
  friend std::istream &operator>>(std::istream &cin, MyString &ms);

  private:
    char *str;

  public:
    // Constructors / Destructor
    MyString(const char *str = nullptr);
    MyString(const MyString &ms);
    MyString(MyString &&ms);
    ~MyString();

    // Operations
    MyString &operator=(const MyString &ms);
    MyString &operator=(MyString &&ms);

    MyString operator+(const MyString &ms) const;
    MyString operator-(const MyString &ms) const;
    MyString operator*(const int value) const;
    MyString operator/(const int value) const;

    MyString &operator+=(const MyString &ms);
    MyString &operator-=(const MyString &ms);
    MyString &operator*=(const int value);
    MyString &operator/=(const int value);

    MyString operator-() const;
    MyString &operator++();
    MyString operator++(int);
    MyString &operator--();
    MyString operator--(int);

    bool operator==(const MyString &ms) const;
    bool operator!=(const MyString &ms) const;
    bool operator>(const MyString &ms) const;
    bool operator<(const MyString &ms) const;
    bool operator>=(const MyString &ms) const;
    bool operator<=(const MyString &ms) const;

    // Getters
    int length() const;
    const char *get_str() const;
};

#endif
