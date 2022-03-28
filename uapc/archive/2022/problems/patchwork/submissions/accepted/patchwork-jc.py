#! /usr/bin/python3

MAXN = 105

R, C = map(int, input().split())
Q, P = [['.' for j in range(2*MAXN)] for i in range(2*MAXN)], []
for _ in range(int(input())):
    r, c = map(int, input().split())
    patch = [input() for i in range(r)]
    P.append((r, c, patch))

for _ in range(int(input())):
    a, b, i = map(int, input().split())
    for da in range(P[i-1][0]):
        for db in range(P[i-1][1]):
            Q[a+da][b+db] = P[i-1][2][da][db]

print('\n'.join([''.join(Q[i][:C]) for i in range(R)]))
