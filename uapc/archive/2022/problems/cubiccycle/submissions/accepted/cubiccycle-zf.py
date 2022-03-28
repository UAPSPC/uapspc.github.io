#!/bin/python3

def toggle(i, w):
    marked_e[i] = not marked_e[i]
    marked_v[w] = not marked_v[w]

def other_v(i, v):
    return v^e[i][0]^e[i][1]

def other_e(i, j, v):
    return i^j^g[v][0]^g[v][1]^g[v][2]

def dfs(v, pi, d):
    if d == 0: return v == 0

    if v == 0 and pi != -1: return 0

    if on_stack[v]: return 0
    on_stack[v] = True

    tot = 0
    for i in g[v]:
        if i == pi or marked_e[i]: continue

        if v == 0:
            tot += dfs(other_v(i, v), i, d-1)
        else:
            oi = other_e(i, pi, v)
            ow = other_v(oi, v)
            if marked_v[ow]: continue
            toggle(oi, ow)
            tot += dfs(other_v(i, v), i, d-1)
            toggle(oi, ow)

    on_stack[v] = False

    return tot

n = int(input())
m = 3*n//2

g = [[] for _ in range(n)]
e = []
marked_e = [False]*m
on_stack = [False]*n
marked_v = [False]*n

for i in range(m):
    u, v = map(int, input().split())
    g[u].append(i)
    g[v].append(i)
    e.append((u,v))

print(dfs(0, -1, n)//2)
