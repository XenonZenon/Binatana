///////////////////////////////
/// Author: Jayson B. Abad  ///
/// Company: Noysoft        ///
/// Start Date: August 2022 ///
/// Update: December 2022   ///
///////////////////////////////

#include <bintana/bintana.h>

Makina::Makina(Game* game)
{
  this->game = game;
  this->window = Window(
    game->getTitle(),
    game->getWidth(),
    game->getHeight()
  );
}

void Makina::simula()
{
  this->window.initialize();
  this->window.setVulkan();
  this->window.periperals();
}

void Makina::ikot()
{
  this->game->simula();

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
    this->game->bago(deltatime);
    this->game->iguhit();
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
  this->game->dulo();
}

void Makina::linis()
{
  delete(this->game);
  this->window.linis();
  glfwDestroyWindow(this->window.getWindow());
  glfwTerminate();
}

void Makina::run()
{
  this->simula();
  this->ikot();
  this->linis();
}

Makina::~Makina(){}
