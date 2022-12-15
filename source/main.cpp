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
    MyGame(){}

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
  Makina makina;
  Game* mygame = new MyGame();
  try{
    makina.simula();
    makina.ikot(mygame);
    makina.linis();
    delete(mygame);
  }
  catch (const std::exception &e)
  {
    std::cerr << "MAY::MALI::" << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
