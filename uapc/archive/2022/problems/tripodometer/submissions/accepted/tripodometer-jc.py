#! /usr/bin/python3

n, D = int(input()), list(map(int, input().split()))
sm = sum(D)

print(len(set([sm-d for d in D])))
print(*sorted(set([sm-d for d in D])))
