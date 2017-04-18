#include <iostream>
#include <cstdlib>
#include "Game.hpp"
#include "AI.hpp"
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


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
/*

  srand(time(NULL));

  for (int i = 0; i < 100; i++) {
    int random_action = rand() % 4 + 1;
    cout << random_action << endl;
    switch (random_action) {
      case 1:
        if (MyGame->Up()) {
          cout << "we did up!" << endl;
          break;
        }
    case 2:
      if (MyGame->Down()) {
        cout << "we did down!" << endl;
        break;
      }
    case 3:
      if (MyGame->Left()) {
        cout << "we did left!" << endl;
        break;
      }
    case 4:
      if (MyGame->Right()) {
        cout << "we did Right!" << endl;
        break;
      }
    default:
      if (MyGame->Up()) {
        cout << "we did up!" << endl;
        break;
      } else if (MyGame->Down()) {
        cout << "we did Down!" << endl;
        break;
      } else {
        cout << "we did left!" << endl;
        MyGame->Left();
        break;
      }
  }
  MyGame->DisplayBoard();



  }
*/
  
  return 0;



}

