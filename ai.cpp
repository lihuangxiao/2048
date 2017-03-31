#include <iostream>
#include "ai.hpp"
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

AI::AI() {}

void AI::play(Game* game) {
  switch (this->play_state) {
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
      break;
  }
}







int AI::learnNextStep(Game* game) {

  srand(time(NULL));
  int tmp_actions[100];
  int tmp_knowledge = 100;
  int up, down, left, right = 0;
  // calculating up
  tmp_actions[0] = 1;
  for (int counter = 0; counter < 100; counter++) {
    for (int i = 1; i < 100; i++) {
      tmp_actions[i] = rand() % 4 + 1;
    }
    Game* tmpGame = new Game(*game);
    tmpGame->play(tmp_actions, tmp_knowledge);
    up += tmpGame->score;
    delete tmpGame;
  }
  up = up / 100;
  //calculating down
  tmp_actions[0] = 2;
  for (int counter = 0; counter < 100; counter++) {
    for (int i = 1; i < 100; i++) {
      tmp_actions[i] = rand() % 4 + 1;
    }
    Game* tmpGame = new Game(*game);
    tmpGame->play(tmp_actions, tmp_knowledge);
    down += tmpGame->score;
    delete tmpGame;
  }
  down = down / 100;
  //calculating left
  tmp_actions[0] = 3;
  for (int counter = 0; counter < 100; counter++) {
    for (int i = 1; i < 100; i++) {
      tmp_actions[i] = rand() % 4 + 1;
    }
    Game* tmpGame = new Game(*game);
    tmpGame->play(tmp_actions, tmp_knowledge);
    left += tmpGame->score;
    delete tmpGame;
  }
  left = left / 100;
  //calculating right
  tmp_actions[0] = 4;
  for (int counter = 0; counter < 100; counter++) {
    for (int i = 1; i < 100; i++) {
      tmp_actions[i] = rand() % 4 + 1;
    }
    Game* tmpGame = new Game(*game);
    tmpGame->play(tmp_actions, tmp_knowledge);
    right += tmpGame->score;
    delete tmpGame;
  }
  right = right / 100;


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




















































