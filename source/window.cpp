#include <bintana/bintana.h>

VkResult Window::CreateDebugUtilsMessengerEXT(
    VkInstance instance,
    const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDebugUtilsMessengerEXT* pDebugMessenger)
  {
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    if (func != nullptr) {
        return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
    } else {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

void Window::DestroyDebugUtilsMessengerEXT(
  VkInstance instance,
  VkDebugUtilsMessengerEXT debugMessenger,
  const VkAllocationCallbacks* pAllocator) {
    auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
    if (func != nullptr) {
        func(instance, debugMessenger, pAllocator);
    }
}

void Window::VulkanCreateInstance()
{
  VkApplicationInfo appInfo{};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = this->title.c_str();
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "Bintana";
  appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;

  createInfo.enabledLayerCount = 0;

  if (vkCreateInstance(&createInfo, nullptr, &this->instance) != VK_SUCCESS) {
      throw std::runtime_error("failed to create instance!");
  }
}

void Window::populateDebugMessengerCreateInfo(
  VkDebugUtilsMessengerCreateInfoEXT& createInfo) {
    createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    createInfo.pfnUserCallback = debugCallback;
}

void Window::setupDebugMessenger()
{
  if (!enablevalidationlayers) return;

  VkDebugUtilsMessengerCreateInfoEXT createInfo;
  this->populateDebugMessengerCreateInfo(createInfo);

  if (this->CreateDebugUtilsMessengerEXT(this->instance, &createInfo, nullptr, &this->debugMessenger) != VK_SUCCESS) {
      throw std::runtime_error("failed to set up debug messenger!");
  }
}

bool Window::checkValidationLayerSupport()
{
  uint32_t layercount;
  vkEnumerateInstanceLayerProperties(&layercount, NULL);
  std::vector<VkLayerProperties> availablelayers(layercount);
  vkEnumerateInstanceLayerProperties(&layercount, availablelayers.data());

  for(const char* layername : validationlayers)
  {
    bool layerfound = false;
    for(const auto& layerproperties : availablelayers)
    {
      if(strcmp(layername, layerproperties.layerName) == 0)
      {
        layerfound = true;
        break;
      }
    }

    if(!layerfound)
    {
      return false;
    }
  }

  return true;
}

std::vector<const char*> Window::getRequiredExtensions()
{
  uint32_t glfwextensioncount = 0;
  const char** glfwextensions;

  glfwextensions = glfwGetRequiredInstanceExtensions(&glfwextensioncount);
  std::vector<const char*> extensions(glfwextensions, glfwextensions + glfwextensioncount);

  if(enablevalidationlayers)
  {
    extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
  }

  return extensions;
}

Window::Window(std::string title, int width, int height)
{
  this->title = title;
  this->width = width;
  this->height = height;
}

Window::Window(){}

void Window::initialize()
{
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  this->window = glfwCreateWindow(
    this->width,
    this->height,
    this->title.c_str(),
    NULL,
    NULL
  );

  glfwSetWindowMonitor(this->window, NULL,
  (GetSystemMetrics(SM_CXSCREEN)/2) - (this->width/2),
  (GetSystemMetrics(SM_CYSCREEN)/2) - (this->height/2),
  this->width, this->height, GLFW_DONT_CARE);

  glfwShowWindow(this->window);

  if(this->window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
  }
}

void Window::setVulkan()
{
  this->VulkanCreateInstance();
  this->setupDebugMessenger();
}

void Window::periperals()
{
  // CURSOR
  unsigned char pixels[16 * 16 * 4];
  memset(pixels, 0xab, sizeof(pixels));

  GLFWimage image;
  image.width = 16;
  image.height = 16;
  image.pixels = pixels;

  this->cursor = glfwCreateCursor(&image, 0, 0);
  glfwSetCursor(this->window, this->cursor);
  glfwSetCursorPos(this->window, this->width / 2, this->height / 2);
}

GLFWwindow* Window::getWindow(){

  return this->window;
}

void Window::linis()
{
  if(enablevalidationlayers)
  {
    this->DestroyDebugUtilsMessengerEXT(this->instance, this->debugMessenger, NULL);
  }

  vkDestroyInstance(instance, NULL);
}

Window::~Window(){}
