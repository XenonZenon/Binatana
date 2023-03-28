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

#include <bintana/game/game.h>
#include <bintana/core/window.h>

class Makina
{
private:
  Window window;

public:
  Makina(Game);
  ~Makina();
  void simula();
  void ikot(Game);
  void linis();

  void takbo(Game);

};

#endif
