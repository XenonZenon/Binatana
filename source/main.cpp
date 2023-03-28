///////////////////////////////
/// Author: Jayson B. Abad  ///
/// Company: Noysoft        ///
/// Start Date: August 2022 ///
/// Update: December 2022   ///
///////////////////////////////

#include <bintana/bintana.h>

class MyGame : public Game
{

public:
    MyGame(std::string title, int width, int height)
    : Game(title, width, height)
    {}

    virtual ~MyGame(){}

    void simula() override
    {

    }
    void bago(double deltatime) override
    {

    }
    void iguhit() override
    {

    }
    void dulo() override
    {
    }
};

int main()
{

  const uint32_t WIDTH = 1200;
  const uint32_t HEIGHT = 680;

  try{
    Game* mygame = new MyGame("Bintana", WIDTH, HEIGHT);
    Makina makina(mygame);
    makina.run();
    delete(mygame);
  }
  catch (const std::exception &e)
  {
    std::cerr << "MAY::MALI::" << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
