#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
typedef long long ll;

using namespace std;
#define MAXN 105

int n;
vector<ll> roll_sm = {0};
ll dist[MAXN][MAXN];
int best[MAXN];

// returns max # num of restaurants can build
// where a is max allowed distance and b is min distance
int query(ll a, ll b) {
    priority_queue<pair<int, int>> Q;
    int mx = 1;
    for (int l = 0, r = 0; r < n; ++r) {
        while (l < r && dist[r][l] >= b) {
            Q.push({best[l], l});
            ++l;
        }
        while (Q.size() && (dist[r][Q.top().second] > a))
            Q.pop();

        best[r] = 1;
        if (Q.size()) best[r] += Q.top().first;
        mx = max(mx, best[r]);
    }
    return mx;
}

int main() {
    int k, d;
    ll lo, hi, mi, ans = (1ll << 62), mx_a = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> d;
        roll_sm.push_back(roll_sm[i] + d);
    }
    unordered_set<ll> B;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j) {
            dist[i][j] = dist[j][i] = roll_sm[i] - roll_sm[j];
            B.insert(dist[i][j]);
            mx_a = max(mx_a, dist[i][j]);
        }

    for (auto& b : B) {
        lo = b - 1, hi = b + ans;
        if (query(hi, b) < k) continue;
        while (hi - lo > 1) {
            mi = (hi + lo)/2;
            if (query(mi, b) >= k) hi = mi;
            else lo = mi;
        }
        ans = min(ans, hi-b);
    }
    cout << ans << endl;

    return 0;
}
