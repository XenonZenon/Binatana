///////////////////////////////
/// Author: Jayson B. Abad  ///
/// Company: Noysoft        ///
/// Start Date: August 2022 ///
/// Update: December 2022   ///
///////////////////////////////

#include <bintana/bintana.h>

Game::Game(std::string title, int width, int height)
{
  this->title = title;
  this->width = width;
  this->height = height;
}

void Game::simula(){}
void Game::bago(double deltatime){}
void Game::iguhit(){}
void Game::dulo(){}

std::string Game::getTitle()
{
  return this->title;
}

int Game::getWidth()
{
  return this->width;
}

int Game::getHeight()
{
  return this->height;
}

Game::~Game(){}
