#include "hello.h"
#include <iostream>
#include <string>

class MyHello : public Hello
{
public:
  MyHello(std::string title, int width, int height)
  : Hello(title, width, height)
  {}
  virtual ~MyHello(){}

};

int main()
{
  std::cout << "Hello World" << std::endl;
  Hello* hello = new MyHello("hello", 1200, 680);
  hello->printdata();
  delete(hello);
}
