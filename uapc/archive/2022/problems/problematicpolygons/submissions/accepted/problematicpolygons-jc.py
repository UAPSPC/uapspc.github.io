#!/usr/bin/python3

from math import *

eps = 10e-6

def dot(a, b): return a[0]*b[0] + a[1]*b[1]
def norm_sq(v): return v[0]*v[0] + v[1]*v[1]

def toVec(a, b):
    return (b[0] - a[0], b[1] - a[1])

def angle(a, o, b):
    oa, ob = toVec(o, a), toVec(o, b)
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)))

def cross(a, b):
    return a[0]*b[1] - a[1]*b[0]

def ccw(p, q, r):
    return cross(toVec(p, q), toVec(p, r)) > 0

def in_poly(p, A):
    if len(A) == 0: return False
    sm = 0
    for i in range(len(A)):
        if ccw(p, A[i], A[(i+1)%len(A)]):
            sm += angle(A[i], p, A[(i+1)%len(A)])
        else:
            sm -= angle(A[i], p, A[(i+1)%len(A)])

    return abs(abs(sm)-2*pi) < eps

def rotate_point(p, theta):
    rad = theta*pi/180
    return (p[0]*cos(rad) - p[1]*sin(rad), p[0]*sin(rad) + p[1]*cos(rad))

def rotate_poly(P, theta):
    return [rotate_point(p, theta) for p in P]

def on_seg(p, q, r):
    return q[0] <= max(p[0], r[0]) and q[0] >= min(p[0], r[0]) and y[1] <= max(p[1], r[1]) and q[1] >= min(p[1], r[1])

def orient(p, q, r):
    val = (q[1]-p[1])*(r[0]-q[0]) - (q[0]-p[0])*(r[1]-q[1])
    if abs(val) < eps: return 0
    return 1 if val > 0 else 2

def seg_inter(p1, q1, p2, q2):
    o1 = orient(p1, q1, p2)
    o2 = orient(p1, q1, q2)
    o3 = orient(p2, q2, p1)
    o4 = orient(p2, q2, q1)

    if o1 != o2 and o3 != o4: return True
    if o1 == 0 and on_seg(p1, p2, q1): return True
    if o2 == 0 and on_seg(p1, q2, q1): return True
    if o3 == 0 and on_seg(p2, p1, q2): return True
    if o4 == 0 and on_seg(p2, q1, q2): return True

    return False

# returns if true if Q contains R
# line intersection for each pair of line segs in R against Q
# if no pairs of lines intersect and first line end-points of R
# is inside Q, then R is entirely inside Q.
def poly_contains():
    for i in range(len(R)):
        p1, q1 = R[i], R[(i+1)%n];
        if not in_poly(p1, Q): return False
        for j in range(m):
            p2, q2 = Q[j], Q[(j+1)%m]
            if seg_inter(p1, q1, p2, q2): return False
    return True

n, m = map(int, input().split())
P = [tuple(map(float, input().split())) for _ in range(n)]
Q = [tuple(map(float, input().split())) for _ in range(m)]

phi = -1
for theta in range(360):
    R = rotate_poly(P, theta)
    if poly_contains():
        phi = theta
        break

print(phi if phi >= 0 else "impossible")
