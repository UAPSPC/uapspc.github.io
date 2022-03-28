#include <bits/stdc++.h>

using namespace std;

using ld = long double;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  auto h = [=](ld x) {
    return max(x*x + A*x + B, x*x + C*x + D);
  };

  ld x = -A*0.5;
  ld best = h(x);

  if (h(-C*0.5) < h(x)) x = -C*0.5;

  // see if the quadratics intersect: solve for f(x) = g(x)
  // if A == C, either they do not intersect or they are identical,
  // in either case we have already computed the answer

  if (A != C) {
    ld xx = ld(D-B)/ld(A-C);
    if (h(xx) < h(x)) x = xx;
  }

  cout.setf(ios::fixed);
  cout.precision(10);

  cout << x << ' ' << h(x) << endl;

  return 0;
}
