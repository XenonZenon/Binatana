#ifndef WINDOW_H
#define WINDOW_H

#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstring>
#include <cstdlib>

#ifndef NDEBUG
  const bool enablevalidationlayers = false;
#else
  const bool enablevalidationlayers = true;
#endif

const std::vector<const char*> validationlayers = {
  "VK_LAYER_KHRONOS_validation"
};

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
  VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
  VkDebugUtilsMessageTypeFlagsEXT messageType,
  const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
  void* pUserData)
  {
    std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;
    return VK_FALSE;
}

class Window
{
private:
  GLFWwindow*              window;
  GLFWcursor*              cursor;
  VkInstance               instance;
  VkDebugUtilsMessengerEXT debugMessenger;
  std::string              title;
  int                      width;
  int                      height;

public:
  Window(std::string, int, int);
  Window();
  ~Window();

  VkResult CreateDebugUtilsMessengerEXT(
    VkInstance,
    const VkDebugUtilsMessengerCreateInfoEXT*,
    const VkAllocationCallbacks*,
    VkDebugUtilsMessengerEXT*
  );
  void DestroyDebugUtilsMessengerEXT(
    VkInstance,
    VkDebugUtilsMessengerEXT,
    const VkAllocationCallbacks*
  );
  void VulkanCreateInstance();
  void populateDebugMessengerCreateInfo(
    VkDebugUtilsMessengerCreateInfoEXT&
  );
  void setupDebugMessenger();
  bool checkValidationLayerSupport();
  std::vector<const char*> getRequiredExtensions();

  void initialize();
  void setVulkan();
  void periperals();
  GLFWwindow* getWindow();
  void linis();

};


#endif
