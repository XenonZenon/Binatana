///////////////////////////////
/// Author: Jayson B. Abad  ///
/// Company: Noysoft        ///
/// Start Date: August 2022 ///
/// Update: December 2022   ///
///////////////////////////////

#include <bintana/bintana.h>

Makina::Makina(){}

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

void Makina::glfwinit()
{
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  this->bintana = glfwCreateWindow(
    this->vars.getWidth(),
    this->vars.getHeight(),
    this->vars.getTitle().c_str(),
    NULL,
    NULL
  );

  glfwSetWindowMonitor(bintana, NULL,
  (this->vars.getMaxWidth()/2) - (this->vars.getWidth()/2),
  (this->vars.getMaxHeight()/2) - (this->vars.getHeight()/2),
  this->vars.getWidth(), this->vars.getHeight(), GLFW_DONT_CARE);

  glfwShowWindow(this->bintana);

  if(this->bintana == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
  }
}

void Makina::vulkaninit()
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

  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;
  createInfo.enabledLayerCount = 0;

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

  uint32_t extensionCount = 0;
  vkEnumerateInstanceExtensionProperties(
    NULL,
    &extensionCount,
    NULL
  );
  std::vector<VkExtensionProperties> extensions(extensionCount);
  vkEnumerateInstanceExtensionProperties(
    NULL,
    &extensionCount,
    extensions.data()
  );

  std::cout << "available extensions:\n";
  for(const auto& extension : extensions)
  {
    std::cout << '\t' << extension.extensionName << '\n';
  }
}

void Makina::periperals()
{
  /// CURSOR
  unsigned char pixels[16 * 16 * 4];
  memset(pixels, 0xab, sizeof(pixels));

  GLFWimage image;
  image.width = 16;
  image.height = 16;
  image.pixels = pixels;

  this->cursor = glfwCreateCursor(&image, 0, 0);
  glfwSetCursor(this->bintana, this->cursor);
  glfwSetCursorPos(this->bintana, this->vars.getWidth() / 2, this->vars.getHeight() / 2);
}

void Makina::simula()
{
  this->glfwinit();
  this->vulkaninit();
  this->periperals();
}

void Makina::ikot(Game* game)
{
  game->simula();

  static double fps = 1.0f / 60.0f;
  double lasttime = glfwGetTime();
  double timer = lasttime;
  double deltatime = 0;
  double currenttime = 0;
  int frames;

  while(!glfwWindowShouldClose(this->bintana))
  {
    glfwPollEvents();
    currenttime = glfwGetTime();
    deltatime += (currenttime - lasttime) / fps;
    lasttime = currenttime;
    while(deltatime >= 1.0)
    {
      deltatime--;
    }
    game->bago(deltatime);
    game->iguhit();
    frames++;
    if(glfwGetTime() - timer > 1.0)
    {
      timer++;
      std::string title = "Bintana | FPS: " + std::to_string(frames);
      glfwSetWindowTitle(this->bintana, title.c_str());
      frames = 0;
    }
    glfwSwapBuffers(this->bintana);
  }
  game->dulo();
}
void Makina::linis()
{
  vkDestroyInstance(this->instance, NULL);
  glfwDestroyWindow(this->bintana);
  glfwTerminate();
}

Makina::~Makina(){}