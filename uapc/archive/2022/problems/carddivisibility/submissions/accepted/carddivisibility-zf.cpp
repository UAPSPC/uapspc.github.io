#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ll a, b;
  cin >> a >> b;

  auto psum = [=](ll x) {
    x %= 9;
    ll t = 0;
    for (ll i = 1; i <= x; ++i) t += i;
    return t%9;
  };

  cout << (psum(b) - psum(a+8) + 9)%9 << endl;


  return 0;
}
