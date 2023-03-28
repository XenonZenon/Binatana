#ifndef HELLO_H
#define HELLO_H

#include <string>

class Hello
{
private:
  std::string title;
  int width;
  int height;

public:
  Hello(std::string, int, int);
  Hello();
  ~Hello();

  void printdata();
  virtual void printsomething();
};

#endif
