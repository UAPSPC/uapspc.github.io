#! /usr/bin/python3

import sys
sys.setrecursionlimit(1500)

n, k = map(int, input().split())

g = {i:{} for i in range(n)}

tot = 0
for _ in range(n-1):
    u, v, w = map(int, input().split())
    g[u][v] = g[v][u] = w
    tot += w;

munch = set(map(int, input().split()))
munch.add(0)

while True:
    found = False
    for v in g:
        if len(g[v]) == 1 and v not in munch:
            u = list(g[v].keys())[0]
            g.pop(v)
            tot -= g[u].pop(v)
            found = True
            break
    if not found: break

print(2*tot)
