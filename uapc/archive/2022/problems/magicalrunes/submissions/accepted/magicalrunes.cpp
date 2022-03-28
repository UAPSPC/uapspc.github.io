#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int n;
  cin >> s >> n;

  int val = 0;
  for (int i = 0; i < s.length(); ++i)
    if (s[i] == 'B')
      val += (1<<i);

  val += n;

  for (int i = 0; i < s.length(); ++i)
    cout << (val & (1<<i) ? 'B' : 'A');
  cout << endl;

  return 0;
}
