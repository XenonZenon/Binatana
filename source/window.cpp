#include <bintana/bintana.h>

Window::Window(std::string title, int width, int height)
{
  std::cout << this->width << std::endl;
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  this->window = glfwCreateWindow(
    width,
    height,
    title.c_str(),
    NULL,
    NULL
  );

  glfwSetWindowMonitor(this->window, NULL,
  (GetSystemMetrics(SM_CXSCREEN)/2) - (width/2),
  (GetSystemMetrics(SM_CYSCREEN)/2) - (height/2),
  width, height, GLFW_DONT_CARE);

  glfwShowWindow(this->window);

  if(this->window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
  }
}

Window::Window(){}

const std::vector<const char*> validationlayers = { "VK_LAYER_KHRONOS_validation" };

#ifndef NDEBUG
  const bool enablevalidationlayers = false;
#else
  const bool enablevalidationlayers = true;
#endif

bool checkValidationLayerSupport()
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

std::vector<const char*> getRequiredExtensions()
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

void Window::setVulkan()
{
  if(enablevalidationlayers && !checkValidationLayerSupport())
  {
    throw std::runtime_error("validation layers requested, but not available!");
  }

  VkApplicationInfo appinfo{};
  appinfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appinfo.pApplicationName = "Bintana";
  appinfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
  appinfo.pEngineName = "Bintana";
  appinfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
  appinfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appinfo;

  auto extensions = getRequiredExtensions();
  createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
  createInfo.ppEnabledExtensionNames = extensions.data();

  if(vkCreateInstance(&createInfo, NULL, &this->instance) != VK_SUCCESS)
  {
    throw std::runtime_error("failed to create instance!");
  }

  if(enablevalidationlayers)
  {
    createInfo.enabledLayerCount = static_cast<uint32_t>(validationlayers.size());
    createInfo.ppEnabledExtensionNames = validationlayers.data();
  }
  else
  {
    createInfo.enabledLayerCount = 0;
  }

  // VkDebugUtilsMessengerCreateInfoEXT createInfo{};
  // createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
  // createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
  //                              VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
  //                              VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
  // createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
  //                          VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT;
  // createInfo.pfnUserCallback = debugCallback;
  // craeteInfo.pUserData = NULL;
}

void Window::periperals()
{
  /// CURSOR
  // unsigned char pixels[16 * 16 * 4];
  // memset(pixels, 0xab, sizeof(pixels));
  //
  // GLFWimage image;
  // image.width = 16;
  // image.height = 16;
  // image.pixels = pixels;
  //
  // this->cursor = glfwCreateCursor(&image, 0, 0);
  // glfwSetCursor(this->bintana, this->cursor);
  // glfwSetCursorPos(this->bintana, this->vars.getWidth() / 2, this->vars.getHeight() / 2);
}

GLFWwindow* Window::getWindow(){

  return this->window;
}

void Window::linis()
{
  vkDestroyInstance(this->instance, NULL);
}

Window::~Window(){}
