#ifndef ai
#define ai
#include "Game.hpp"


// implements the AI player for 2048 game
class AI
{
public:
  AI();
  void play(Game* game);
  int play_state;
  int learnNextStep(Game* game);
  void randomPlay(Game* game);
};




#endif
