#! /usr/bin/python3

input()

trips = list(map(int, input().split()))

tot = sum(trips)

rem = {tot - x for x in trips}

print(len(rem))
print(*sorted(rem))
