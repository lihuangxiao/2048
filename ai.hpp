#ifndef ai
#define ai
#include "game.hpp"

class AI
{
public:
  AI();
  void play(Game* game);
  int play_state;

  int learnNextStep(Game* game);

};




#endif
