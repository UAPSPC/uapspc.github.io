#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  auto h = [=](float x) {
    return max(x*x + A*x + B, x*x + C*x + D);
  };

  float x = -A*0.5;
  float best = h(x);

  if (h(-C*0.5) < h(x)) x = -C*0.5;

  // see if the quadratics intersect: solve for f(x) = g(x)
  // if A == C, either they do not intersect or they are identical,
  // in either case we have already computed the answer

  if (A != C) {
    float xx = float(D-B)/float(A-C);
    if (h(xx) < h(x)) x = xx;
  }

  cout << x << ' ' << h(x) << endl;

  return 0;
}
