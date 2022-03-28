#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> uf;

struct point {
  int x, y, i;
};

int find(int u) {
   return u == uf[u] ? u : uf[u] = find(uf[u]);
}

int merge(int u, int v) {
  u = find(u);
  v = find(v);
  uf[u] = v;
  return u != v;
}

int main() {
  int n;
  cin >> n;
  int comp = n;

  unordered_map<int, point> ldiag, rdiag;

  for (int i = 0; i < n; ++i) {
    uf.push_back(i);

    point p;
    cin >> p.x >> p.y;
    p.i = i;

    int ld = p.x-p.y, rd = p.x+p.y;

    if (ldiag.find(ld) != ldiag.end()) {
      comp -= merge(i, ldiag[ld].i);
    }
    else {
      ldiag[ld] = p;
      for (int j = -1; j <= 1; j += 2)
        if (ldiag.find(ld+j) != ldiag.end())
          comp -= merge(i, ldiag[ld+j].i);
    }

    if (rdiag.find(rd) != rdiag.end()) {
      comp -= merge(i, rdiag[rd].i);
    }
    else {
      rdiag[rd] = p;
      for (int j = -1; j <= 1; j += 2)
        if (rdiag.find(rd+j) != rdiag.end())
          comp -= merge(i, rdiag[rd+j].i);
    }
  }

  cout << comp << endl;

  return 0;
}
