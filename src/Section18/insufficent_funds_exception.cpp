#include <iostream>
#include "insufficent_funds_exception.h"

const char *insufficent_funds_exception::what() const noexcept
{
  return "Insuficient funds exception";
}
