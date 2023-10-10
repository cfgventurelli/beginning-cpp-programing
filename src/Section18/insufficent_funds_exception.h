#ifndef _INSUFFICENT_FUNDS_EXCEPTION_H_
#define _INSUFFICENT_FUNDS_EXCEPTION_H_

#include <iostream>
#include "i_exception.h"

class insufficent_funds_exception: public i_exception
{
  public:
    insufficent_funds_exception() noexcept = default;
    ~insufficent_funds_exception() = default;
    virtual const char *what() const noexcept;
};

#endif