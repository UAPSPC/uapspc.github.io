#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
#define MAXN 1005

vector<vector<pair<int, int>>> G;
unordered_set<int> S;

int sm = 0;

bool dfs(int s, int p) {
    bool b = S.count(s);
    for (auto& e : G[s])
        if (e.first != p && dfs(e.first, s)) {
            sm += 2*e.second;
            b = true;
        }
    return b;
}

int main() {
    int n, k, s, t, d;
    cin >> n >> k;
    G.resize(n);

    for (int i = 0; i < n-1; ++i) {
        cin >> s >> t >> d;
        G[s].push_back({t, d});
        G[t].push_back({s, d});
    }
    
    for (int i = 0; i < k; ++i) {
        cin >> s;
        S.insert(s);
    }

    dfs(0, -1);
    cout << sm << endl;

    return 0;
}