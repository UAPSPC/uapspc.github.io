#!/usr/bin/python3

def find(u):
    while u != uf[u]:
        uf[u], u = uf[uf[u]], uf[u]
    return uf[u]

def merge(u, v):
    up, vp = find(u), find(v)
    uf[up] = vp
    return (up != vp)

n, cnt = int(input()), 0

uf = list(range(n+1))
UD, DD = dict(), dict()

L = list(map(int, input().split()))
for u in range(n):
    r, c = L[2*u], L[2*u+1]
    for i in range(-1, 2):
        if r+c+i in UD: cnt += merge(u, UD[r+c+i])
        if r-c+i in DD: cnt += merge(u, DD[r-c+i])
    UD[r+c] = DD[r-c] = u

print(n-cnt)
