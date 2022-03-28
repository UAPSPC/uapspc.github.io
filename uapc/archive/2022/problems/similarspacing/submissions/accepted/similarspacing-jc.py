#!/usr/bin/python3

from heapq import *

MAXN = 105

dist = [[0 for j in range(MAXN)] for i in range(MAXN)]
best = [0]*MAXN

# returns max # num of restaurants can build
# where a is max allowed distance and b is min distance
def query(a, b):
    Q = []
    mx, l = 1, 0
    for r in range(n):
        while l < r and dist[r][l] >= b:
            heappush(Q, (-best[l], l))
            l += 1

        while Q and dist[r][Q[0][1]] > a:
            heappop(Q)

        best[r] = 1
        if Q: best[r] -= Q[0][0]
        mx = max(mx, best[r])

    return mx

n, k = map(int, input().split())
ans, mx_a = (1 << 62), 0
roll_sm, B = [0]*(n+1), set()

for i, d in enumerate(map(int, input().split())):
    roll_sm[i+1] = roll_sm[i] + d

for i in range(n):
    for j in range(i):
        dist[i][j], dist[j][i] = roll_sm[i] - roll_sm[j], dist[i][j]
        B.add(dist[i][j])
        mx_a = max(mx_a, dist[i][j])

for b in B:
    lo, hi = b - 1, b + ans
    if (query(hi, b) < k): continue

    while hi - lo > 1:
        mi = (hi+lo)//2
        if query(mi, b) >= k: hi = mi
        else: lo = mi

    ans = min(ans, hi-b)

print(ans)
