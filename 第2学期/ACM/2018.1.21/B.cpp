#include <iostream>
using namespace std;

const int N = 10;
int A[N];

int main()
{
  for (int i = 1; i < N; i++) A[i] = (1 << (i-1)) * ((1<<i) - 1);

  int n;
  cin >> n;
  for (int i = N-1; i > 0; i--)
    if (n % A[i] == 0) {cout << A[i] << endl; return 0;}

  return 0;
}

