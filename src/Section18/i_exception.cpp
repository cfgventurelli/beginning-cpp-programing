#include <iostream>
#include "i_exception.h"

std::ostream &operator<<(std::ostream &os, const i_exception &e)
{
  os << e.what() << std::endl;
  return os;
}