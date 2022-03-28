/*
  Enumerate all perfect matchings. Check to see if their deletion leaves
  a connected graph, thus a Hamiltonian cycle.

  There are O(sqrt(2)^n) perfect matchings. To see this, consider the following
  algorithm to generate all perfect matchings.

  From vertex 0, try all 3 incident edges in the matching and recurse on each.
  In the recursion, try a vertex v that is adjacent to a vertex that is
  matched. There are only <= 2 choices for it to be matched since one of
  its neighbours is already matched.

  So the recursion has depth n/2 (each call matches two nodes) and branching
  factor <= 2 (except the initial call which spawns 3 recursions).

  This will generate all perfect matchings in the component with 0.

  This code will enqueue (on a stack) all neighbours of the two nodes
  that were just matched. When looking for a neighbour of a node to match,
  look at the top of the stack. If this node has since been matched, pop it
  and look again. Just make sure to restore the stack to it's original state
  after recursing with a choice.

  Running time: O(sqrt(2)^n * n). This code is an extra logarithmic factor
  slower because it does the connectivity check using union/find with only
  path compression. But one could use a DFS instead to improve the O()
  running time.
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m;
ll ans;
vector<vector<int>> g;
vector<vector<int>> ok;
vector<bool> matched;
stack<int> check;

vector<int> uf;

int find (int v) {
  return uf[v] == v ? v : (uf[v] = find(uf[v]));
}

bool merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  uf[u] = v;
  return true;
}

bool connected() {
  uf.resize(n);
  iota(uf.begin(), uf.end(), 0);

  int comp = n;
  for (int u = 0; u < n; ++u)
    for (int v : g[u])
      if (ok[u][v])
        comp -= merge(u, v);
  return comp == 1;
}

void generate(int rem) {
  if (rem == 0) {
    ans += connected();
    return;
  }

  if (check.size() == 0) return;

  int v = check.top();
  check.pop();

  if (matched[v]) {
    generate(rem);
  }
  else {
    for (int u : g[v]) {
      if (matched[u]) continue;

      ok[u][v] = ok[v][u] = false;
      matched[u] = matched[v] = true;
      for (int w : g[v]) if (!matched[w]) check.push(w);
      for (int w : g[u]) if (!matched[w]) check.push(w);

      generate(rem-2);

      for (int w : g[u]) if (!matched[w]) check.pop();
      for (int w : g[v]) if (!matched[w]) check.pop();
      matched[u] = matched[v] = false;
      ok[u][v] = ok[v][u] = true;
    }
  }

  check.push(v);
}

int main() {
  cin >> n;
  m = 3*n/2;
  g.resize(n);
  ok.assign(n, vector<int>(n, 1));
  matched.assign(n, false);

  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  check.push(0);
  generate(n);
  cout << ans << endl;

  return 0;
}
