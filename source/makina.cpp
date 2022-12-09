#include <bintana/bintana.h>


Makina::Makina(){}


void Makina::simula()
{
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  this->bintana = glfwCreateWindow(
    this->vars.getWidth(),
    this->vars.getHeight(),
    this->vars.getTitle().c_str(),
    nullptr,
    nullptr
  );

  glm::mat4 matrix;
  glm::vec4 vec;
  auto test = matrix * vec;
}

void Makina::ikot(Game* game)
{

  game->simula();
  while(!glfwWindowShouldClose(this->bintana ))
  {
    glfwPollEvents();
    game->bago();
  }
  game->dulo();
}
void Makina::linis()
{
  glfwDestroyWindow(this->bintana );
  glfwTerminate();
}

Makina::~Makina(){}
