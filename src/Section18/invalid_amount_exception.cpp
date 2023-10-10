#include <iostream>
#include "invalid_amount_exception.h"

const char *invalid_amount_exception::what() const noexcept
{
  return "Invalid amount exception";
}
