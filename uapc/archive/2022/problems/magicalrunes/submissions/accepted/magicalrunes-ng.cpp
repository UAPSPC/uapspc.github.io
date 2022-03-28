#include <bits/stdc++.h>
using namespace std;

string s;
int d, val;

int main() {
    
    cin >> s >> d;

    for (int i = 0; i < s.length(); i++)
        val |= (s[i] == 'B' ? 1 << i : 0);
    val += d;

    for (int i = 0; i < s.length(); i++)
        cout << ((val >> i) & 1 ? 'B' : 'A');
    cout << '\n';
    
    return 0;
}
