#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull powmod(ull x, ull a, ull m) {
  return a?(((a&1)?x:1)*powmod((x*x)%m, a>>1, m))%m:(1%m);
}

int main() {
  ull n, m;
  cin >> n >> m;

  cout << (n?5*powmod(2, n-1, m)-1:2)%m << endl;

  return 0;
}
