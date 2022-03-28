#! /usr/bin/python3

L = []

def same_sign(a, b):
    return (a < 0) == (b < 0)

def push(x):
    while x:
        if not L or same_sign(x, L[-1]):
            L.append(x)
            break
        x += L.pop()

n = int(input())
for x in map(int, input().split()):
    push(x)

if not L:
    print("Tie!")
else:
    print("Positives" if L[0] > 0 else "Negatives", "win!")
    print(' '.join(map(str, L)))