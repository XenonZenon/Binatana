#include <bintana/bintana.h>


Makina::Makina(){}


void Makina::simula()
{
  /// GLFW
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  this->bintana = glfwCreateWindow(
    this->vars.getWidth(),
    this->vars.getHeight(),
    this->vars.getTitle().c_str(),
    nullptr,
    nullptr
  );

  /// VULKAN
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

  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;
  createInfo.enabledLayerCount = 0;

  if(vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
  {
    throw std::runtime_error("failed to create instance!");
  }

  uint32_t extensionCount = 0;
  vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
  std::vector<VkExtensionProperties> extensions(extensionCount);
  vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

  std::cout << "available extensions:\n";
  for(const auto& extension : extensions)
  {
    std::cout << '\t' << extension.extensionName << '\n';
  }
}

void Makina::ikot(Game* game)
{
  game->simula();
  while(!glfwWindowShouldClose(this->bintana))
  {
    glfwPollEvents();
    game->bago();
  }
  game->dulo();
}
void Makina::linis()
{
  vkDestroyInstance(instance, nullptr);
  glfwDestroyWindow(this->bintana);
  glfwTerminate();
}

Makina::~Makina(){}
