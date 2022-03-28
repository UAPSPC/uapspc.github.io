#! /usr/bin/python3

r, c = map(int, input().split())

n = int(input())

patches = []

for _ in range(n):
    nr, nc = map(int, input().split())
    patch = [input() for _ in range(nr)]
    patches.append((nr, nc, patch))

pattern = [['.']*c for _ in range(r)]

placements = []

for _ in range(int(input())):
    pr, pc, i = map(int, input().split())
    placements.append((pr, pc, i-1))

for ir in range(r):
    out = ""
    for ic in range(c):
        ch = "."
        for pr, pc, pi in placements:
            rr, cc = ir-pr, ic-pc
            if rr in range(patches[pi][0]) and cc in range(patches[pi][1]):
                ch = patches[pi][2][rr][cc]
        out += ch
    print(out)
