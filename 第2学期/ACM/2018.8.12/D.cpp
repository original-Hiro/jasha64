#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

long long P3[36];
char c[36];
void Decode(int& l, long long& p)
{
  l = p = 0;
  int len = strlen(c);
  for (int i = 0; i < len; i++) {
    if (c[i] == 's') {p = (p+1) % P3[l];}
    else if (c[i] == 'a') {p = (p-1+P3[l]) % P3[l];}
    else if (c[i] == 'c') {l++; p *= 3;}
    else {l--; p /= 3;}
  }
}
inline long long Abs(long long x) {return x < 0 ? -x : x;}

queue<char> s1, r1;
stack<char> s2, r2;
long long s, Res = 280;
long long rd;
int rdir, rl; //dir, dist, l of res
int l1, l2;
long long p1, p2;
inline void One_CC() {s1.push('s'); p1 = (p1 + 1) % P3[l1]; s++;}
inline void One_C() {s1.push('a'); s++;}
inline void One_Down() {p1 /= 3; l1--; s1.push('g'); s++;}
inline void Two_CC() {s2.push('a'); p2 = (p2 + 1) % P3[l2]; s++;}
inline void Two_C() {s2.push('s'); s++;}
inline void Two_Down() {p2 /= 3; l2--; s2.push('c'); s++;}
inline void One_Calc()
{
  if (p1 % 3 == 2) One_CC();
  else if (p1 % 3 == 1) One_C();
  One_Down();
}
inline void Two_Calc()
{
  if (p2 % 3 == 2) Two_CC();
  else if (p2 % 3 == 1) Two_C();
  Two_Down();
}
inline void Update(long long d) {Res = d+s; rd = d; r1 = s1; r2 = s2; rl = l1;}

int main()
{
  P3[0] = 1;
  for (int i = 1; i <= 35; i++) P3[i] = P3[i-1] * 3;
  scanf("%s", c);
  Decode(l1, p1);
  scanf("%s", c);
  Decode(l2, p2);

  while (l2 != l1) {
    if (l1 > l2) One_Calc();
    else Two_Calc();
  }
  while (l1 >= 0) {
    long long d = (p2 - p1 + P3[l1]) % P3[l1];
    if (d + s < Res) {rdir = 1; Update(d);}
	d = (p1 - p2 + P3[l1]) % P3[l1];
	if (d + s < Res) {rdir = -1; Update(d);}
	One_Calc(); Two_Calc();
  }
  
  while (!r1.empty()) {putchar(r1.front()); r1.pop();}
  for (int i = 0; i < rd; i++) putchar(rdir == 1 ? 's' : 'a');
  while (!r2.empty()) {putchar(r2.top()); r2.pop();}
  putchar('\n');
  return 0;
}

