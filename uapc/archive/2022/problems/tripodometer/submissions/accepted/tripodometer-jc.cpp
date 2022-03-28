#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

int main() {
    int n, i = 0;
    cin >> n;
    vector<int> D(n);
    set<int> S;

    for (auto& d : D)
        cin >> d;

    int sm = accumulate(D.begin(), D.end(), 0);
    for (auto& d : D) S.insert(sm-d);

    cout << S.size() << endl;
    for (auto& s : S)
        if (!i++) cout << s;
        else cout << ' ' << s;
    cout << endl;
    return 0;
}
