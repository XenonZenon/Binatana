///////////////////////////////
/// Author: Jayson B. Abad  ///
/// Company: Noysoft        ///
/// Start Date: August 2022 ///
/// Update: December 2022   ///
///////////////////////////////

#include <bintana/bintana.h>

Makina::Makina(Game game)
{
  this->window = Window(
    game.getTitle(),
    game.getWidth(),
    game.getHeight()
  );
}

void Makina::simula()
{
  this->window.setVulkan();
  this->window.periperals();
}

void Makina::ikot(Game game)
{
  game.simula();

  static double fps = 1.0f / 60.0f;
  double lasttime = glfwGetTime();
  double timer = lasttime;
  double deltatime = 0;
  double currenttime = 0;
  int frames;

  while(!glfwWindowShouldClose(this->window.getWindow()))
  {
    glfwPollEvents();
    currenttime = glfwGetTime();
    deltatime += (currenttime - lasttime) / fps;
    lasttime = currenttime;
    while(deltatime >= 1.0)
    {
      deltatime--;
    }
    game.bago(deltatime);
    game.iguhit();
    frames++;
    if(glfwGetTime() - timer > 1.0)
    {
      timer++;
      std::string title = "Bintana | FPS: " + std::to_string(frames);
      glfwSetWindowTitle(this->window.getWindow(), title.c_str());
      frames = 0;
    }
    glfwSwapBuffers(this->window.getWindow());
  }
  game.dulo();
}

void Makina::linis()
{
  // if(enablevalidationlayers)
  // {
  //   DestroyDebugUtilMessagerEXT(this->instance, debugMessanger, NULL);
  // }
  this->window.linis();
  glfwDestroyWindow(this->window.getWindow());
  glfwTerminate();
}

void Makina::takbo(Game game)
{
  this->simula();
  this->ikot(game);
  this->linis();
}

Makina::~Makina(){}
