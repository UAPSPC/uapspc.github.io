#!/bin/python3

# Python 3 Solution to Is it Even?

n, k = map(int, input().split())
exp = 0

'''
To solve this problem, you just need to keep track of the factors
of 2 in each term. If the total exp of the 2 factors is >= k,
then 2^k divides the overall product.
'''

# Loop through every x_i.
for _ in range(n):
    x = int(input())
    
    while x % 2 == 0:
        x //= 2
        exp += 1

# Print result.
print(1 if exp >= k else 0)
