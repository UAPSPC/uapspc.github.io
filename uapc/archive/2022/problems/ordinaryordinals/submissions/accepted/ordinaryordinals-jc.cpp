#include <iostream>

using namespace std;
typedef unsigned long long ll;

ll binpow(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return res;
}

int main() {
    ll n, m;
    cin >> n >> m;
    cout << (n ? (binpow(2, n+1, m)+binpow(2, n-1, m)-1) : 2) % m << endl;
    return 0;
}
