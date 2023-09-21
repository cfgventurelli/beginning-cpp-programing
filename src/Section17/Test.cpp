#include <iostream>
#include "Test.h"


/*****************************************************************************/
// Constructors / Destructor
/*****************************************************************************/
Test::Test(int data)
  : data {data}
{
  std::cout << "\tTest constructor (" << this->data << ")" << std::endl;
}

Test::~Test()
{
  std::cout << "\tTest destructor (" << this->data << ")" << std::endl;
}


/*****************************************************************************/
// Getters
/*****************************************************************************/
int Test::get_data() const
{
  return this->data;
}