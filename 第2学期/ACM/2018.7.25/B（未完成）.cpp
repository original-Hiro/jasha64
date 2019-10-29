#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
using namespace std;

typedef pair<int, int> pii;
const int N = 2007;
int a[N];
map<pii, int> m1;
map<multiset<int>, int> m2;

int main()
{
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    m1.clear();

    int n;
    cin >> n;
    for (int i = 0, c, b; i < n; i++) {
      cin >> c >> b;
      if (c > b) swap(c, b);
      pii p = pii(c, b);
      if (m1.find(p) == m1.end()) m1[p] = i;
      a[i] = m1[p];
    }

    long long Res = 0;
    for (int k = 1; k <= n; k++) {
      m2.clear();
      multiset<int> ss;
      for (int j = 0; j < k; j++) ss.insert(a[j]);
      int Cnt = 0;
      for (int i = 0; i+k <= n; i++) {
	if (m2.find(ss) != m2.end()) m2[ss]++;
	else m2[ss] = 1;
	ss.erase(ss.find(a[i])); ss.insert(a[i+k]);
      }

      for (map<multiset<int>, int>::iterator I = m2.begin(); I != m2.end(); I++) {
	int c = I -> second;
	Res += c * (c-1) / 2;
      }
    }
    cout << Res << endl;
  }

  return 0;
}

