#!/bin/python3

L, R = map(int, input().split())

def psum(x): return sum(range(x%9 + 1))

print((psum(R) - psum(L+8))%9)
