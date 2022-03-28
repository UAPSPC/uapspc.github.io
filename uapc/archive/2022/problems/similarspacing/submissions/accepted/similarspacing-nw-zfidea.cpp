#include<bits/stdc++.h>
using namespace std;
int n,k;
#define MAXN 101
long dl[MAXN];
long d[MAXN][MAXN];
long f[MAXN];
vector<int> R;
bool query(long a, long b) {
    long best=0;
    R.clear();
    int o=0;
    int j=0;
    for(int i=0; i<n; i++) {
        while (o<R.size() && d[i][R[o]] > a) o++;
        while (j<i && d[i][j] > a) j++;
        while (j<i && d[i][j] >= b) R.push_back(j++);
        long m = 0;
        for (int k=o; k<R.size(); k++)
            m = max(m, f[R[k]]);
        f[i] = 1+m;
        best = max(best, f[i]);
    }
    return best >= k;
}
int main() {
    cin>>n>>k;
    for(int i=0; i<n-1; i++)
        cin>>dl[i];
    unordered_set<long> dists;
    long xd=0;
    for(int i=0; i<n; i++) {
        long l=0;
        for(int j=i; j<n; j++) {
            d[j][i] = d[i][j] = l;
            dists.insert(l);
            xd = max(xd, l);
            l += dl[j];
        }
    }
    long best=(1ul<<31)*MAXN;
    for(long b : dists) {
        long lo=b-1;
        long hi=min(xd,best+b);
        while (hi-lo>1) {
            long mid = (lo+hi)/2;
            if (query(mid, b))
                hi=mid;
            else
                lo=mid;
        }
        if (query(hi, b))
            best = min(best, hi-b);
    }
    cout<<best<<endl;
}
