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
    MyGame(std::string title, int width, int height){}

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
  try{
    Game mygame = MyGame("Bintana", 1200, 620);
    Makina makina = Makina(mygame);
    makina.takbo(mygame);
  }
  catch (const std::exception &e)
  {
    std::cerr << "MAY::MALI::" << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
