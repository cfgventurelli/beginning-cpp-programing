#ifndef _TEST_H_
#define _TEST_H_

class Test
{
  private:
    int data;
  public:
    // Constructors / Destructor
    Test(int data = 0);
    ~Test();

    // Getters
    int get_data() const;
};

#endif
