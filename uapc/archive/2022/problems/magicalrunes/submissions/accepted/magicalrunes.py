#!/bin/python3

s, n = input().split()
n = int(n)

val = int(s.replace('A', '0').replace('B', '1')[::-1], 2) + n

t = bin(val)[2:]
while len(t) < len(s): t = "0"+t

print(t[::-1].replace('0', 'A').replace('1', 'B'))
