// Running time: O(n * 2^{n/2})

#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

vector<bool> marked_e, marked_v, on_stack;
vector<pii> e;
vector<vi> g;

void toggle(int i, int w) {
  marked_e[i] = !marked_e[i];
  marked_v[w] = !marked_v[w];
}

int other_v(int i, int v) {
  return v^e[i].first^e[i].second;
}

int other_e(int i, int j, int v) {
  return i^j^g[v][0]^g[v][1]^g[v][2];
}

int dfs(int v, int pi, int d) {
  if (d == 0) return v == 0;

  if (v == 0 && pi != -1) return 0;

  if (on_stack[v]) return 0;
  on_stack[v] = true;

  int tot = 0;
  for (int i : g[v]) {
    if (i == pi || marked_e[i]) continue;

    if (v == 0) tot += dfs(other_v(i, v), i, d-1);
    else {
      int oi = other_e(i, pi, v);
      int ow = other_v(oi, v);
      if (marked_v[ow]) continue;
      toggle(oi, ow);
      tot += dfs(other_v(i, v), i, d-1);
      toggle(oi, ow);
    }
  }
  on_stack[v] = false;

  return tot;
}

int main() {
  int n;
  cin >> n;
  int m = 3*n/2;
  g.resize(n);
  e.resize(m);
  marked_e.resize(m);
  on_stack.resize(n);
  marked_v.resize(n);

  for (int i = 0; i < m; ++i) {
    cin >> e[i].first >> e[i].second;
    g[e[i].first].push_back(i);
    g[e[i].second].push_back(i);
  }

  cout << dfs(0, -1, n)/2 << endl;
}
