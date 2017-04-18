#include <iostream>
#include <cstdlib>
#include "Game.hpp"
#include "AI.hpp"
using namespace std;

int main(int argc, char** argv)
{
  Game* MyGame = new Game();
  AI* MyAI = new AI();


  while (!MyGame->GameOver()) {
    MyAI->play_state = MyAI->learnNextStep(MyGame);
    MyAI->play(MyGame);
    MyGame->DisplayBoard();
  }
  MyGame->DisplayBoard();
  
  return 0;
}

