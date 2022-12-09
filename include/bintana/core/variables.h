#ifndef VARIABLES_H
#define VARIABLES_H

#include <string>

class Variable
{

private:
  std::string    title;
  int            width;
  int            height;
  int            max_width;
  int            max_height;

public:
  Variable();
  ~Variable();
  std::string getTitle();
  int getWidth();
  int getHeight();
  int getMaxWidth();
  int getMaxHeight();

};

#endif
