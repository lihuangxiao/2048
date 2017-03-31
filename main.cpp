#include <iostream>
#include "game.hpp"
#include "ai.hpp"
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


int main(int argc, char** argv)
{
  Game* MyGame = new Game();
  AI* MyAI = new AI();


  for (int i = 0; i < 10000; i++) {
    MyAI->play_state = MyAI->learnNextStep(MyGame);
    MyAI->play(MyGame);
    MyGame->DisplayBoard();
  }

  
  return 0;



}

