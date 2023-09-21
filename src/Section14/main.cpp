/*
Section 14 Challenge
====================

Overload the following operators in the provided MyString class.

To gain experience overloading operators, you should do this challenge twice.
First, overload the operators using member functions and then in another project overload the same operators
again using non-member functions.

Please do it once using member methods and then again using non-member functions.

Here is a list of some of the operators that you can overload for this class:

-       - unary minus. Returns the lowercase version of the object's string
           -s1
==    - returns true if the two strings are equal
           (s1 == s2)
!=     - returns true if the two strings are not equal 
           (s1 != s2)
<      - returns true if the lhs string is lexically less than the rhs string
           (s1 < s2)
>      - returns true if the lhs string is lexically greater than the rhs string
          (s1 > s2)
+       - concatenation. Returns an object that concatenates the lhs and rhs
           s1 + s2
+=    - concatenate the rhs string to the lhs string and store the result in lhs object
          s1 += s2;      equivalent to s1 = s1 + s2;
*        - repeat -  results in a string that is copied n times
          s2 * 3;          ex). s2 = "abc"; 
                                   s1 = s2 * 3;
                                   s1 will result in "abcabcabc"
*=      - repeat the string on the lhs n times and store the result back in the lhs object
            s1 = "abc";
            s1 *= 4;        s1 = s1 will result in "abcabcabcabc"
      
If you wish to overlod the ++ and -- operators remember that they have pre and post versions.

The semantics should be as follows (this shows the member method version):

MyString &operator++()   {  // pre-increment
   // do what ever you want increment do to - maybe make all characters uppercase?
   return *this;
}

// Note that post-increment returns a MyString by value not by reference
MyString operator++(int) {   // post-increment
   MyString temp (*this);       // make a copy
   operator++();                    // call pre-increment - make sure you call pre-increment!
   return temp;                     // return the old value
}


Have fun! Think of some other operators that might be useful!
Don't worry if they all don't make sense -- this is an exercise about learning how
to overload operators.

Hints:
1. take advantage of the std::strcmp function for the equality operators!
2. the += and *= operators should return a MyString &
3. rather than duplicate code in the += and *= functions, use the + and * operators which you have already overloaded!
*/

#include <iostream>
#include "MyString.h"

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

const char SEPARATOR[] {"==============================\n"};

int main()
{
  cout << boolalpha << endl;

  MyString a {"frank"};
  MyString b {"frank"};

  cout << a << " == " << b << " = " << (a == b) << endl;   // true
  cout << a << " != " << b << " = " << (a != b) << endl;   // false
  cout << a << "  > " << b << " = " << (a > b) << endl;    // false
  cout << a << " >= " << b << " = " << (a >= b) << endl;   // true
  cout << a << "  < " << b << " = " << (a < b) << endl;    // false
  cout << a << " <= " << b << " = " << (a <= b) << endl;   // true
  cout << SEPARATOR << endl;

  {b = "george";}
  cout << a << " == " << b << " = " << (a == b) << endl;   // false
  cout << a << " != " << b << " = " << (a != b) << endl;   // true
  cout << a << "  > " << b << " = " << (a > b) << endl;    // false
  cout << a << " >= " << b << " = " << (a >= b) << endl;   // false
  cout << a << "  < " << b << " = " << (a < b) << endl;    // true
  cout << a << " <= " << b << " = " << (a <= b) << endl;   // true
  cout << SEPARATOR << endl;

  {b = "ann";}
  cout << a << " == " << b << " = " << (a == b) << endl;   // false
  cout << a << " != " << b << " = " << (a != b) << endl;   // true
  cout << a << "  > " << b << " = " << (a > b) << endl;    // true
  cout << a << " >= " << b << " = " << (a >= b) << endl;   // true
  cout << a << "  < " << b << " = " << (a < b) << endl;    // false
  cout << a << " <= " << b << " = " << (a <= b) << endl;   // false
  cout << SEPARATOR << endl;

  MyString c;

  {c = a + b;}
  cout << a << " + " << b << " = " << c << endl;
  cout << SEPARATOR << endl;

  {b = "an";}
  {c = a - b;}
  cout << a << " - " << b << " = " << c << endl;
  cout << SEPARATOR << endl;

  {b = "aN";}
  {c = a - b;}
  cout << a << " - " << b << " = " << c << endl;
  cout << SEPARATOR << endl;

  int value;
  {value = 3;}
  c = a * value;
  cout << a << " * " << value << " = " << c << endl;
  cout << SEPARATOR << endl;

  {a = "hubert";}
  value = 2;
  {c = a / value;}
  cout << a << " / " << value << " = " << c << endl;
  cout << SEPARATOR << endl;

  {b = "nickname";}
  {c = a;}
  {c += b;}
  cout << a << " += " << b << " = " << c << endl;
  cout << SEPARATOR << endl;

  {a = c;}
  {b = "tni";}
  {c -= b;}
  cout << a << " -= " << b << " = " << c << endl;
  cout << SEPARATOR << endl;

  value = 4;
  {a = "Jackson";}
  {c = a;}
  {c *= value;}
  cout << a << " *= " << value << " = " << c << endl;
  cout << SEPARATOR << endl;

  value = 2;
  {c /= value;}
  cout << a << " /= " << value << " = " << c << endl;
  cout << SEPARATOR << endl;

  {b = ++a;}
  cout << "b = ++a => " << b << "  " << a << endl;
  cout << SEPARATOR << endl;

  {b = a++;}
  cout << "b = a++ => " << b << "  " << a << endl;
  cout << SEPARATOR << endl;

  {a = "Alexander";}
  {c = --a;}
  cout << "c = --a => " << c << "  " << a << endl;
  cout << SEPARATOR << endl;

  {c = a--;}
  cout << "c = a-- => " << c << "  " << a << endl;
  cout << SEPARATOR << endl;

  return 0;
}