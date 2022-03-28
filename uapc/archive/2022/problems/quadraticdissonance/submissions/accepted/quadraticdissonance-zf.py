#!/bin/python3

A, B, C, D = map(int, input().split())

def h(x): return max(x*x+A*x+B, x*x+C*x+D)

xx = [-A/2, -C/2]
if A != C: xx.append((D-B)/(A-C))

x = min(xx, key = lambda x : h(x))
print(x, h(x))
