#include<bits/stdc++.h>
using namespace std;

int n, adj[51][3], deg[51], inpath[51], ninpath = 0;
int solve(int v) {
    if (ninpath == n-1)
        return !(adj[v][0] && adj[v][1] && adj[v][2]);
    inpath[v] = 1; ninpath++;
    int opts[3], nopts = 0, ans = 0;
    for (int i = 0; i < 3; i++)
        if (!inpath[adj[v][i]]) opts[nopts++] = adj[v][i];
    for (int i = 0; i < nopts; i++) {
        int u = opts[i];
        if (nopts == 2) {
            int w = opts[1-i], nwonpath = 0;
            for (int j = 0; j < 3; j++) nwonpath += adj[w][j] && inpath[adj[w][j]];
            if (nwonpath == 2) continue;
        }
        ans += solve(u);
    }
    inpath[v] = 0; ninpath--;
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < 3*n/2; i++) {
        int u,v;
        cin >> u >> v;
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }
    cout << solve(0)/2 << endl;
}
