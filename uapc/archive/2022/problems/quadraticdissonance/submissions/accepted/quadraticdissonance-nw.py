#!/usr/bin/python3
import  random
a,b,c,d=map(int,input().split())
def h(x):
    return max(x*x+a*x+b, x*x+c*x+d)
bestx = 0
besty = 10000000
for r in range(1,30):
    for s in range(1000):
        x = (s/500-1)/(2**r)*1000 + bestx
        y = h(x)
        if y < besty:
            bestx = x
            besty = y
print(bestx,besty)
