#ifndef GAME
#define GAME

//this is a dummy 2048 game where there is no randomness.

// helper class to implement 4 consecutive tiles in order
class Arr4
{
public:
  Arr4();
  Arr4(int a, int b, int c, int d);
  int ReArrange();
  bool CheckNoMove();

  int MyArr[4];
};


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
  int play (int actions[], int knowledge);



  int score;
  int board[16];
  bool CheckOccupied(int pos);    

};


#endif
