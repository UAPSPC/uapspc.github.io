#! /usr/bin/python3

import sys
sys.setrecursionlimit(1500)

n, k = map(int, input().split())

g = {i:[] for i in range(n)}

for _ in range(n-1):
    u, v, w = map(int, input().split())
    g[u].append((v,w))
    g[v].append((u,w))

visit = set(map(int, input().split()))

def search(u, p):
    seen = (u in visit)
    tot = 0
    for v, w in g[u]:
        if v != p:
            ret, hit = search(v, u)
            if hit:
                seen = True
                tot += ret + w
    return tot, seen

print(2*search(0, -1)[0])
