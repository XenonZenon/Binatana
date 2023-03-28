#include <iostream>
#include "hello.h"

Hello::Hello(){}

Hello::Hello(std::string title, int width, int height)
{
  this->title = title;
  this->width = width;
  this->height = height;
}

void Hello::printsomething(){}

void Hello::printdata()
{
  std::cout << "This is the hello class" << std::endl;
  std::cout << "Title: " << this->title << std::endl;
  std::cout << "Width: " << this->width << std::endl;
  std::cout << "Height: " << this->height << std::endl;
}

Hello::~Hello(){}
