#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
#define MAXN 105

char Q[2*MAXN][2*MAXN];

struct Patch {
    int r, c;
    vector<vector<char>> design;
    Patch(int _r, int _c) : r(_r), c(_c) {
        design.resize(r, vector<char>(c));
    }
};

int main() {
    memset(Q, '.', sizeof(Q));
    int R, C, n, m, r, c, a, b, idx;
    cin >> R >> C >> n;
    vector<Patch> P;

    for (int i = 0; i < n; ++i) {
        cin >> r >> c;
        P.push_back(Patch(r, c));
        for (int j = 0; j < r; ++j)
            for (int k = 0; k < c; ++k)
                cin >> P[i].design[j][k];
    }

    cin >> m;
    while (m--) {
        cin >> a >> b >> idx;
        for (int da = 0; da < P[idx-1].r; ++da)
            for (int db = 0; db < P[idx-1].c; ++db)
                Q[a+da][b+db] = P[idx-1].design[da][db];
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) cout << Q[i][j];
        cout << endl;
    }
    
    return 0;
}