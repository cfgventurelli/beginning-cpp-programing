#ifndef _I_EXCEPTION_H_
#define _I_EXCEPTION_H_

#include <iostream>

class i_exception: public std::exception
{
  friend std::ostream &operator<<(std::ostream &os, const i_exception &e);
  public:
    i_exception() noexcept = default;
    ~i_exception() = default;
    virtual const char *what() const noexcept = 0;
};

#endif
