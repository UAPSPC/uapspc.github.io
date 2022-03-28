#!/usr/bin/python3

# using built-in pow(a, b, m) would also work.
def binpow(a, b, m):
    res = 1
    while b > 0:
        if b & 1: res = res*a%m
        a = a*a%m
        b >>= 1
    return res

n, m = map(int, input().split())
print((binpow(2, n+1, m) + binpow(2, n-1, m) - 1)%m)
