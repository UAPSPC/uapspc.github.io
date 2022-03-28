#! /usr/bin/python3

import sys
from collections import defaultdict
sys.setrecursionlimit(1500)

n, k = map(int, input().split())
G = defaultdict(list)

for _ in range(n-1):
    s, t, d = map(int, input().split())
    G[s].append((t, d))
    G[t].append((s, d))

D, S = dict(), set(map(int, input().split()))

def dfs(s, p):
    b = s in S
    for t, d in G[s]:
        if t != p and dfs(t, s):
            D[(s, t)], D[(t, s)] = d, d
            b = True
    return b

dfs(0, -1)
print(sum(D.values()))