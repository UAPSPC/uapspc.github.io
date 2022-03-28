#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> trips(n);

  int tot = 0;
  for (int& x : trips) {
    cin >> x;
    tot += x;
  }

  set<int> rem;
  for (int x : trips) rem.insert(tot-x);

  cout << rem.size() << endl;
  bool first = true;
  for (int x : rem) {
    if (first) first = false;
    else cout << ' ';
    cout << x;
  }
  cout << endl;

  return 0;
}
