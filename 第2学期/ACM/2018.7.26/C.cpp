#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;

  int a = 0, p = s.find("LSC");
  while (p != -1) {
    a++; p = s.find("LSC", p+1);
  }
  int b = 0; p = s.find("PCMS");
  while (p != -1) {
    b++; p = s.find("PCMS", p+1);
  }

  if (a > b) cout << "LSC" << endl;
  else if (a < b) cout << "PCMS" << endl;
  else cout << "Tie" << endl;

  return 0;
}

