#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 10e-6;

struct point {
    double x, y;
    point(double _x=0, double _y=0) : x(_x), y(_y) {}
};

struct vec {
    double x, y;
    vec(double _x=0, double _y=0) : x(_x), y(_y) {}
};

int n, m, theta;
vector<point> P, Q, R;

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b) { return (a.x*b.x + a.y*b.y); }
double norm_sq(vec v) { return v.x*v.x + v.y*v.y; }

double angle(point a, point o, point b) {
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) {
    return a.x*b.y-a.y*b.x;
}

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool in_poly(point p, const vector<point> &A) {
    if (A.size() == 0) return false;
    double sm = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (ccw(p, A[i], A[(i+1)%A.size()]))
            sm += angle(A[i], p, A[(i+1)%A.size()]);
        else
            sm -= angle(A[i], p, A[(i+1)%A.size()]);
    }
    return fabs(fabs(sm)-2*M_PI) < eps;
}

point rotate_point(point p) {
    double rad = theta*M_PI/180;
    return point(p.x*cos(rad)-p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}

bool on_seg(point p, point q, point r) {
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

int orient(point p, point q, point r) {
    double val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    if (abs(val) < eps) return 0;
    return (val > 0) ? 1 : 2;
}

bool seg_inter(point p1, point q1, point p2, point q2) {
    int o1 = orient(p1, q1, p2);
    int o2 = orient(p1, q1, q2);
    int o3 = orient(p2, q2, p1);
    int o4 = orient(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && on_seg(p1, p2, q1)) return true;
    if (o2 == 0 && on_seg(p1, q2, q1)) return true;
    if (o3 == 0 && on_seg(p2, p1, q2)) return true;
    if (o4 == 0 && on_seg(p2, q1, q2)) return true;

    return false;
}

// returns if true if Q contains R
// line intersection for each pair of line segs in R against Q
// if no pairs of lines intersect and first line end-points of R
// is inside Q, then R is entirely inside Q.
bool poly_contains() {
    for (int i = 0; i < n; ++i) {
        point p1 = R[i], q1 = R[(i+1)%n];
        if (!in_poly(p1, Q)) return false;
        for (int j = 0; j < m; ++j) {
            point p2 = Q[j], q2 = Q[(j+1)%m];
            if (seg_inter(p1, q1, p2, q2)) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    P.resize(n);
    Q.resize(m);
    for (auto& p : P) cin >> p.x >> p.y;
    R.resize(P.size());
    for (auto& q : Q) cin >> q.x >> q.y;
    int phi = -1;
    for (theta = 0; theta < 360; ++theta) {
        transform(P.begin(), P.end(), R.begin(), rotate_point);
        if (poly_contains()) {
            phi = theta;
            break;
        }
    }
    if (phi >= 0) cout << phi << endl;
    else cout << "impossible" << endl;
    return 0;
}
