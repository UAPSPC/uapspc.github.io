#!/bin/python3

# I thought of this slightly simpler solution after I did my previous one

L, R = map(int, input().split())

R -= 9*((R-L)//9)

ans = sum(x%9 for x in range(L, R+1))%9

print(ans)
