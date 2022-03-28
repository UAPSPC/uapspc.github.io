#! /usr/bin/python3

import sys, cmath, math

EPS = 1e-8

def rotate(p, theta): return p*cmath.rect(1.0, theta/360.0*2*math.pi)

def dot(p, q): return (p*q.conjugate()).real

def cross(p, q): return (p*q.conjugate()).imag

def isect_line_seg(a, b, c, d):
    if abs(cross(b-a, d-c)) > EPS:
        p = cross(c-a, d-c) / cross(b-a, d-c) * (b - a) + a
        return dot(p-a, p-b) < EPS and dot(p-c, p-d) < EPS
    elif abs(cross(b-a, b-c)) > EPS:
        return False
    else:
        return dot(a-c, a-d) < EPS or dot(b-c, b-d) < EPS or dot(c-a, c-b) < EPS

def point_int_poly(q, poly):
    # don't have to check for on the boundary, the other segment intersection checks this
    angle = 0.0
    for i in range(len(poly)):
        angle += cmath.phase((poly[i]-q)/(poly[i-1]-q))
    return abs(angle) > 1

def solve(inner, outer):
    for theta in range(360):
        rotated = [rotate(p, float(theta)) for p in inner]
        ok = point_int_poly(rotated[0], outer)
        for i in range(n):
            if not ok: break
            for j in range(m):
                if isect_line_seg(rotated[i-1], rotated[i], outer[j-1], outer[j]):
                    ok = False
                    break
        if ok: return theta

    return "impossible"

n, m = map(int, input().split())

inner = [complex(*map(float, input().split())) for _ in range(n)]
outer = [complex(*map(float, input().split())) for _ in range(m)]

print(solve(inner, outer))
