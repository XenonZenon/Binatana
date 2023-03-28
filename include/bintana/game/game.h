///////////////////////////////
/// Author: Jayson B. Abad  ///
/// Company: Noysoft        ///
/// Start Date: August 2022 ///
/// Update: December 2022   ///
///////////////////////////////

#ifndef GAME_H
#define GAME_H

#include <string>

class Game
{

private:
  std::string title;
  int width;
  int height;

public:
  Game(std::string, int, int);
  Game();
  ~Game();

  virtual void simula();
  virtual void bago(double);
  virtual void iguhit();
  virtual void dulo();

  std::string getTitle();
  int getWidth();
  int getHeight();

};

#endif
