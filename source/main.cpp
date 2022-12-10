#include <bintana/bintana.h>

class MyGame : public Game
{
public:
    MyGame(){}
    virtual ~MyGame(){}

    void simula() override
    {

    }
    void bago() override
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
  }
  return 0;
}
