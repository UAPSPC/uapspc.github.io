#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    while (x%2 == 0) {
      --k;
      x /= 2;
    }
  }
  cout << (k <= 0) << endl;
  
  return 0;
}
