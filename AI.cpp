#include <iostream>
#include "AI.hpp"
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

AI::AI() {}

void AI::play(Game* game) {
  switch (this->play_state) {
    case 1:
      game->Up();
      break;
    case 2:
      game->Down();
      break;
    case 3:
      game->Left();
      break;
    case 4:
      game->Right();
      break;
    default:
      break;
  }
}



void AI::randomPlay(Game* game) {
  //srand(time(NULL));
  int random_action = rand() % 4 + 1;
  switch (random_action) {
    case 1:
      if (game->Up()) {
        break;
      }
    case 2:
      if (game->Down()) {
        break;
      }
    case 3:
      if (game->Left()) {
        break;
      }
    case 4:
      if (game->Right()) {
        break;
      }
    default:
      if (game->Up()) {
        break;
      } else if (game->Down()) {
        break;
      } else {
        game->Left();
        break;
      }
  }



}



int AI::learnNextStep(Game* game) {
  srand(time(NULL));
  int up = 0, down = 0, left = 0, right = 0;
  // calculating up
  for (int i = 0; i < 300; i++) {
    Game* tmpGame = new Game(*game);
    if (tmpGame->Up()) {
      while(!tmpGame->GameOver()) {
        this->randomPlay(tmpGame);
      }
      up += tmpGame->score;
    }
    delete tmpGame;
  }
  up = up / 300;
  //calculating down
  for (int i = 0; i < 300; i++) {
    Game* tmpGame = new Game(*game);
    if (tmpGame->Down()) {
      while(!tmpGame->GameOver()) {
        this->randomPlay(tmpGame);
      }
      down += tmpGame->score;
    }
    delete tmpGame;
  }
  down = down / 300;
  //calculating left
  for (int i = 0; i < 300; i++) {
    Game* tmpGame = new Game(*game);
    if (tmpGame->Left()) {
      while(!tmpGame->GameOver()) {
        this->randomPlay(tmpGame);
      }
      left += tmpGame->score;
    }
    delete tmpGame;
  }
  left = left / 300;
  //calculating right
  for (int i = 0; i < 300; i++) {
    Game* tmpGame = new Game(*game);
    if (tmpGame->Right()) {
      while(!tmpGame->GameOver()) {
        this->randomPlay(tmpGame);
      }
      right += tmpGame->score;
    }
    delete tmpGame;
  }
  right = right / 300;


  //game->DisplayBoard();
  //std::cout << "up: " << up << "; down: " << down << "; left: " << left << "; right: " << right << std::endl;



  if ((left > up) && (left >= right) && (left >= down)) {
    return 3;
  } else if ((right > up) && (right >= left) && (right >= down)) {
    return 4;
  } else if ((down > up) && (down >= right) && (down >= left)) {
    return 2;
  } else {
    return 1;
  }
  return 1;


}




















































