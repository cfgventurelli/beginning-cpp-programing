#include <iostream>
#include "withdraw_limit_exception.h"

const char *withdraw_limit_exception::what() const noexcept
{
  return "Withdrawal limit has been reached";
}
