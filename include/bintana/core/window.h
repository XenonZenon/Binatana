#ifndef WINDOW_H
#define WINDOW_H

#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

class Window
{
private:
  GLFWwindow*   window;
  GLFWcursor*   cursor;
  VkInstance    instance;
  std::string   title;
  int           width;
  int           height;
  int           max_width;
  int           max_height;

public:
  Window(std::string, int, int);
  Window();
  ~Window();
  void setVulkan();
  void periperals();

  GLFWwindow* getWindow();

  void linis();

};


#endif
