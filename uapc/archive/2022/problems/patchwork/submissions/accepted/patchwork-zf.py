#! /usr/bin/python3

r, c = map(int, input().split())

n = int(input())

patches = []

for _ in range(n):
    nr, nc = map(int, input().split())
    patch = [input() for _ in range(nr)]
    patches.append((nr, nc, patch))

pattern = [['.']*c for _ in range(r)]

for _ in range(int(input())):
    pr, pc, i = map(int, input().split())
    for rr in range(patches[i-1][0]):
        for cc in range(patches[i-1][1]):
            if (pr+rr in range(r) and pc+cc in range(c)):
                pattern[pr+rr][pc+cc] = patches[i-1][2][rr][cc]

for p in pattern:
    print(*p, sep='')
