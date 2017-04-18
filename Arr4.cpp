#include "Arr4.hpp"

Arr4::Arr4()
{
  MyArr[0] = 0;
  MyArr[1] = 0;
  MyArr[2] = 0;
  MyArr[3] = 0;
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


