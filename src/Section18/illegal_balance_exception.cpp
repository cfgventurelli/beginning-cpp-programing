#include <iostream>
#include "illegal_balance_exception.h"

const char *illegal_balance_exception::what() const noexcept
{
  return "Illegal balance exception";
}
