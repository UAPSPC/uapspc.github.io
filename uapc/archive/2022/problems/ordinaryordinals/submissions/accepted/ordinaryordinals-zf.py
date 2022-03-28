#! /usr/bin/python3

#MOD = 1233950539 # interesting for (n = 42)

n, m = map(int, input().split())

if n == 0:
    ans = 2%m
else:
    ans = (5*pow(2, n-1, m)-1)%m;

print(ans)
