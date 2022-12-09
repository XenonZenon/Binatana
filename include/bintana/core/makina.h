#ifndef ENGINE_H
#define ENGINE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <bintana/core/variables.h>
#include <bintana/game/game.h>

class Makina
{

private:
  GLFWwindow*   bintana;
  GLFWcursor*   cursor;
  Variable vars;

public:
  Makina();
  ~Makina();
  void simula();
  void ikot(Game*);
  void linis();

};

#endif
