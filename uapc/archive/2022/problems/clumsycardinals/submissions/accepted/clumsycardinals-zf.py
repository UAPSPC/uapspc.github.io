#!/usr/bin/python3

def find(u):
    if uf[u] != u: uf[u] = find(uf[u])
    return uf[u];

def union(u, v):
    u, v = find(u), find(v)
    if u != v:
        uf[u] = v
        return 1
    else:
        return 0

comp = n = int(input())

uf, ldiag, rdiag = [i for i in range(n)], {}, {}

vals = list(map(int, input().split()))

for i in range(n):
    x, y = vals[2*i], vals[2*i+1]

    ld, rd = x-y, x+y

    tup = (x, y, i)

    for j in range(-1, 2):
        if ld+j in ldiag: comp -= union(i, ldiag[ld+j][2])
        if rd+j in rdiag: comp -= union(i, rdiag[rd+j][2])
    ldiag[ld] = rdiag[rd] = tup

print(comp)
