#ifndef GAME
#define GAME
#include "Arr4.hpp"


// implements the 2048 game
class Game
{

public:
  Game();
  Game(const Game& other);
  void DisplayBoard();
  bool Up();
  bool Down();
  bool Left();
  bool Right();
  bool GameOver();


  int score;
  int board[16];
  bool CheckOccupied(int pos);    

};


#endif
