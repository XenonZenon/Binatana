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
  } catch (const std::exception &e)
  {
    std::cerr << "Error::" << e.what() << std::endl;
  }

  return 0;
}
