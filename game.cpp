#include <iostream>
#include <cstdlib>
#include "game.hpp"

Arr4::Arr4()
{
}

Arr4::Arr4(int a, int b, int c, int d)
{
  MyArr[0] = a;
  MyArr[1] = b;
  MyArr[2] = c;
  MyArr[3] = d;
}

int Arr4::ReArrange()
{
  int score = 0;
  if ((MyArr[0] > 0) || (MyArr[1] > 0) || (MyArr[2] > 0) || (MyArr[3] > 0))
  {
    while (MyArr[0] == 0)
    {
      MyArr[0] = MyArr[1];
      MyArr[1] = MyArr[2];
      MyArr[2] = MyArr[3];
      MyArr[3] = 0;
    }

    if (MyArr[1] == 0)
    {
      MyArr[1] = MyArr[2];
      MyArr[2] = MyArr[3];
      MyArr[3] = 0;
    }

    if (MyArr[1] == 0)
    {
      MyArr[1] = MyArr[2];
      MyArr[2] = MyArr[3];
      MyArr[3] = 0;
    }

    if (MyArr[2] == 0) 
    {
      MyArr[2] = MyArr[3];
      MyArr[3] = 0;
    }


    if (MyArr[0] == MyArr[1])
    {
      MyArr[0] *= 2;
      score += MyArr[0];
      if (MyArr[2] == MyArr[3])
      {
        MyArr[1] = MyArr[2] + MyArr[3];
        score += MyArr[1];
        MyArr[2] = 0;
        MyArr[3] = 0;
      }
      else
      {
        MyArr[1] = MyArr[2];
        MyArr[2] = MyArr[3];
        MyArr[3] = 0;
      }
    }

    else if (MyArr[1] == MyArr[2])
    {
      MyArr[1] *= 2;
      score += MyArr[1];
      MyArr[2] = MyArr[3];
      MyArr[3] = 0;
    }

    else if (MyArr[2] == MyArr[3])
    {
      MyArr[2] *= 2;
      score += MyArr[2];
      MyArr[3] = 0;
    }
  
  }
  return score;
}


bool Arr4::CheckNoMove()
{
  int a = MyArr[0];
  int b = MyArr[1];
  int c = MyArr[2];
  int d = MyArr[3];
  Arr4* tmp = new Arr4(a, b, c, d);
  tmp->ReArrange();
  bool retval = ((tmp->MyArr[0] == a) && (tmp->MyArr[1] == b) && (tmp->MyArr[2] == c) && (tmp->MyArr[3] == d));
  delete tmp;
  return retval;
}


int newNum()
{
  return 2;
  //return (rand() % 2 + 1) * 2;
} 

int newPos()
{
  return rand() % 16;
}

Game::Game()
{
  srand (time(NULL));
  int a = 14;//newPos();
  int b = 15;//newPos();
  while ( b == a)
  {
    int b = newPos();
  }

  board[a] = newNum();
  board[b] = newNum();
}

Game::Game(const Game& other) {
  for (int i = 0; i < 16; i++) {
    board[i] = other.board[i];
  }
  score = other.score;



}


void Game::DisplayBoard()
{
  std::cout << "current score: " << score << std::endl;
  for (int i = 0; i < 16; i++)
  {
    std::cout << board[i];
    std::cout << " ";
    if (i % 4 == 3)
    {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}


bool Game::CheckOccupied(int pos)
{
  return (this->board[pos] > 0);
}




bool Game::Up()
{
  Arr4* a1 = new Arr4(board[0], board[4], board[8], board[12]);
  Arr4* a2 = new Arr4(board[1], board[5], board[9], board[13]);
  Arr4* a3 = new Arr4(board[2], board[6], board[10], board[14]);
  Arr4* a4 = new Arr4(board[3], board[7], board[11], board[15]);

  if ((a1->CheckNoMove()) && (a2->CheckNoMove()) && (a3->CheckNoMove()) && (a4->CheckNoMove()))
  {
    delete a1;
    delete a2;
    delete a3;
    delete a4;
    return false;
  }

  score += a1->ReArrange();
  score += a2->ReArrange();
  score += a3->ReArrange();
  score += a4->ReArrange();

  board[0] = a1->MyArr[0];
  board[4] = a1->MyArr[1];
  board[8] = a1->MyArr[2];
  board[12] = a1->MyArr[3];

  board[1] = a2->MyArr[0];
  board[5] = a2->MyArr[1];
  board[9] = a2->MyArr[2];
  board[13] = a2->MyArr[3];

  board[2] = a3->MyArr[0];
  board[6] = a3->MyArr[1];
  board[10] = a3->MyArr[2];
  board[14] = a3->MyArr[3];

  board[3] = a4->MyArr[0];
  board[7] = a4->MyArr[1];
  board[11] = a4->MyArr[2];
  board[15] = a4->MyArr[3];

  int Spawn = 15;
  while (CheckOccupied(Spawn))
  {
    Spawn--;
  }
  board[Spawn] = newNum();

  delete a1;
  delete a2;
  delete a3;
  delete a4;

  return true;
}

bool Game::Down()
{
  Arr4* a1 = new Arr4(board[12], board[8], board[4], board[0]);
  Arr4* a2 = new Arr4(board[13], board[9], board[5], board[1]);
  Arr4* a3 = new Arr4(board[14], board[10], board[6], board[2]);
  Arr4* a4 = new Arr4(board[15], board[11], board[7], board[3]);
  
  if ((a1->CheckNoMove()) && (a2->CheckNoMove()) && (a3->CheckNoMove()) && (a4->CheckNoMove()))
  { 
    delete a1;
    delete a2;
    delete a3;
    delete a4;
    return false;
  }
  
  score += a1->ReArrange();
  score += a2->ReArrange();
  score += a3->ReArrange();
  score += a4->ReArrange();

  
  board[12] = a1->MyArr[0];
  board[8] = a1->MyArr[1];
  board[4] = a1->MyArr[2];
  board[0] = a1->MyArr[3];
  
  board[13] = a2->MyArr[0];
  board[9] = a2->MyArr[1];
  board[5] = a2->MyArr[2];
  board[1] = a2->MyArr[3];
  
  board[14] = a3->MyArr[0];
  board[10] = a3->MyArr[1];
  board[6] = a3->MyArr[2];
  board[2] = a3->MyArr[3];
  
  board[15] = a4->MyArr[0];
  board[11] = a4->MyArr[1];
  board[7] = a4->MyArr[2];
  board[3] = a4->MyArr[3];
  
  int Spawn = 15;
  while (CheckOccupied(Spawn))
  { 
    Spawn--;
  }
  board[Spawn] = newNum();

  delete a1;
  delete a2;
  delete a3;
  delete a4;
  return true;
}

bool Game::Left()
{
  Arr4* a1 = new Arr4(board[0], board[1], board[2], board[3]);
  Arr4* a2 = new Arr4(board[4], board[5], board[6], board[7]);
  Arr4* a3 = new Arr4(board[8], board[9], board[10], board[11]);
  Arr4* a4 = new Arr4(board[12], board[13], board[14], board[15]);
  
  if ((a1->CheckNoMove()) && (a2->CheckNoMove()) && (a3->CheckNoMove()) && (a4->CheckNoMove()))
  { 
    delete a1;
    delete a2;
    delete a3;
    delete a4;
    return false;
  }
  
  score += a1->ReArrange();
  score += a2->ReArrange();
  score += a3->ReArrange();
  score += a4->ReArrange();
  
  board[0] = a1->MyArr[0];
  board[1] = a1->MyArr[1];
  board[2] = a1->MyArr[2];
  board[3] = a1->MyArr[3];
  
  board[4] = a2->MyArr[0];
  board[5] = a2->MyArr[1];
  board[6] = a2->MyArr[2];
  board[7] = a2->MyArr[3];
  
  board[8] = a3->MyArr[0];
  board[9] = a3->MyArr[1];
  board[10] = a3->MyArr[2];
  board[11] = a3->MyArr[3];
  
  board[12] = a4->MyArr[0];
  board[13] = a4->MyArr[1];
  board[14] = a4->MyArr[2];
  board[15] = a4->MyArr[3];
  
  int Spawn = 15;
  while (CheckOccupied(Spawn))
  { 
    Spawn--;
  }
  board[Spawn] = newNum();

  delete a1;
  delete a2;
  delete a3;
  delete a4;
  return true;
}

bool Game::Right()
{
  Arr4* a1 = new Arr4(board[3], board[2], board[1], board[0]);
  Arr4* a2 = new Arr4(board[7], board[6], board[5], board[4]);
  Arr4* a3 = new Arr4(board[11], board[10], board[9], board[8]);
  Arr4* a4 = new Arr4(board[15], board[14], board[13], board[12]);
  
  if ((a1->CheckNoMove()) && (a2->CheckNoMove()) && (a3->CheckNoMove()) && (a4->CheckNoMove()))
  { 
    delete a1;
    delete a2;
    delete a3;
    delete a4;
    return false;
  }

  score += a1->ReArrange();
  score += a2->ReArrange();
  score += a3->ReArrange();
  score += a4->ReArrange();
  
  board[3] = a1->MyArr[0];
  board[2] = a1->MyArr[1];
  board[1] = a1->MyArr[2];
  board[0] = a1->MyArr[3];
  
  board[7] = a2->MyArr[0];
  board[6] = a2->MyArr[1];
  board[5] = a2->MyArr[2];
  board[4] = a2->MyArr[3];
  
  board[11] = a3->MyArr[0];
  board[10] = a3->MyArr[1];
  board[9] = a3->MyArr[2];
  board[8] = a3->MyArr[3];
  
  board[15] = a4->MyArr[0];
  board[14] = a4->MyArr[1];
  board[13] = a4->MyArr[2];
  board[12] = a4->MyArr[3];
  
  int Spawn = 15;
  while (CheckOccupied(Spawn))
  { 
    Spawn--;
  }
  board[Spawn] = newNum();

  delete a1;
  delete a2;
  delete a3;
  delete a4;
  return true;
}

int Game::play(int actions[], int knowledge) {
  for (int i = 0; i < knowledge; i++) {
    switch (actions[i]) {
      case 1:
        if (this->Up()) {break;}
      case 2:
        if (this->Down()) {break;}
      case 3:
        if (this->Left()) {break;}
      case 4:
        if (this->Right()) {break;}
      default:
        break;
    }
  }
  return this->score;
}

