#ifndef _INVALID_AMOUNT_EXCEPTION_H_
#define _INVALID_AMOUNT_EXCEPTION_H_

#include <iostream>
#include "i_exception.h"

class invalid_amount_exception: public i_exception
{
  public:
    invalid_amount_exception() noexcept = default;
    ~invalid_amount_exception() = default;
    virtual const char *what() const noexcept;
};

#endif