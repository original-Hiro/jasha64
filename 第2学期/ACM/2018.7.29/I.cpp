#include <iostream>
#include <algorithm>
using namespace std;

int a[4], op[3];
const int P[24] = {
  0, 2, 2, 4, 4, 6,
  2, 4, 4, 6, 6, 8,
  4, 6, 6, 8, 8, 10,
  6, 8, 8, 10, 10, 12
}; //排列加分 
const int B[8] = {
  1, 1, 1, 1, 1, 2, 2, 2
}; //括号加分 

int Val(int l, int r)
{

}
int Calc()
{
  int r = Val(0, 4);
  //(a b) c d
  //(a b c) d
  //a (b c) d
  //a (b c d)
  //a b (c d)
  //(a b)(c d)
  //a (b (c d))
  //a ((b c) d)
}

int main()
{
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  int pcnt = 0, Res = 0x3fffffff;
  do {
    for (op[0] = 0; op[0] < 4; op[0]++)
      for (op[1] = 0; op[1] < 4; op[1]++)
    for (op[2] = 0; op[2] < 4; op[2]++)
      Res = min(Res, Calc() + P[pcnt]);
  } while (next_permutation(a, a+4));
  if (Res == 0x3fffffff) cout << -1 << endl;
  else cout << Res << endl;
  return 0;
}

