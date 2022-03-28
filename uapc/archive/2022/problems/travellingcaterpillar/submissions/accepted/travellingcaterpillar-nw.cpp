#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<pair<int,int>> adj[1000010];
bool mark[1000010];
pair<bool,long long> dfs(int v){
    if (adj[v].size()==0)
        return{mark[v],0};
    long long d=0;
    bool any=0;
    for(auto p:adj[v]) {
        auto c=dfs(p.first);
        d+=c.first?c.second+2*p.second:0;
        any|=c.first;
    }
    return{any,d};
}
int main() {
    memset(mark,0,sizeof mark);
    cin>>n>>k;
    for(int i=0; i<n-1; i++) {
        int s,t,d;
        cin>>s>>t>>d;
        adj[s].emplace_back(t,d);
    }
    for(int i=0; i<k; i++) {
        int j;
        cin>>j;
        mark[j]=1;
    }
    auto x=dfs(0);
    cout<<(x.first?x.second:0)<<endl;
}
