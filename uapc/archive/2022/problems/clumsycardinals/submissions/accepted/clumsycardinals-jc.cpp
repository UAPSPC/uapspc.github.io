#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;
#define MAXN 100005

int uf[MAXN];
unordered_map<int, int> UD, DD;

int find(int u) {
    if (uf[u] != u) uf[u] = find(uf[u]);
    return uf[u];
}

bool merge(int u, int v) {
    int up = find(u), vp = find(v);
    uf[up] = vp;
    return (up != vp);
}

int main() {
    int n, r, c, cnt = 0;
    cin >> n;
    iota(uf, uf+n, 0);
    for (int u = 0; u < n; ++u) {
        cin >> r >> c;
        for (int i = -1; i < 2; ++i) {
            if (UD.count(r+c+i)) cnt += merge(u, UD[r+c+i]);
            if (DD.count(r-c+i)) cnt += merge(u, DD[r-c+i]);
        }
        UD[r+c] = DD[r-c] = u;
    }
    cout << n-cnt << endl;
    return 0;
}
