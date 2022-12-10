///////////////////////////////
/// Author: Jayson B. Abad  ///
/// Company: Noysoft        ///
/// Start Date: August 2022 ///
/// Update: December 2022   ///
///////////////////////////////

#ifndef ENGINE_H
#define ENGINE_H

#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <bintana/core/variables.h>
#include <bintana/game/game.h>

class Makina
{

private:
  GLFWwindow*   bintana;
  GLFWcursor*   cursor;
  Variable      vars;
  VkInstance    instance;

public:
  Makina();
  ~Makina();
  void simula();
  void ikot(Game*);
  void linis();

};

#endif
