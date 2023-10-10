#ifndef _ILLEGAL_BALANCE_EXCEPTION_H_
#define _ILLEGAL_BALANCE_EXCEPTION_H_

#include <iostream>
#include "i_exception.h"

class illegal_balance_exception: public i_exception
{
  public:
    illegal_balance_exception() noexcept = default;
    ~illegal_balance_exception() = default;
    virtual const char *what() const noexcept;
};

#endif