#ifndef ARR4
#define ARR4


// Helper class to implement 4 integers with order.
class Arr4
{
public:
  Arr4();
  Arr4(int a, int b, int c, int d);
  // as if four integers a,b,c,d slides towards a.
  // return value is the sum of new integers.
  int ReArrange();
  // returns true iff it's not possible to "slide toward a" in 2048 game logic.
  bool CheckNoMove();
  int MyArr[4];
};

#endif
