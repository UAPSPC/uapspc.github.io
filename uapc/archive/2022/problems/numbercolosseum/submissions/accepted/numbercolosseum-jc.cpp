#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

#define same_sign(a, b) ((a<0) == (b<0))

deque<int> Q;

void push(int x) {
    if (x == 0) return;

    if (Q.empty() || same_sign(x, Q.back())) {
        Q.push_back(x);
    } else {
        x += Q.back();
        Q.pop_back();
        push(x);
    }
}

int main() {
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        push(x);
    }
    if (Q.empty()) {
        cout << "Tie!" << endl;
    } else {
        cout << (Q.front() > 0 ? "Positives" : "Negatives") << " win!" << endl;
        cout << Q[0];
        for (int i = 1; i < Q.size(); ++i)
            cout << ' ' << Q[i];
        cout << endl;
    }
    return 0;
}
