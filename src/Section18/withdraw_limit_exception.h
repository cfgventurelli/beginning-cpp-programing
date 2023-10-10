#ifndef _WITHDRAW_LIMIT_EXCEPTION_H_
#define _WITHDRAW_LIMIT_EXCEPTION_H_

#include <iostream>
#include "i_exception.h"

class withdraw_limit_exception: public i_exception
{
  public:
    withdraw_limit_exception() noexcept = default;
    ~withdraw_limit_exception() = default;
    virtual const char *what() const noexcept;
};

#endif