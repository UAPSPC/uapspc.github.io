#!/usr/bin/python3

import heapq

def visit(b, a):
    f = {}
    right = 0
    heap = []

    best = 1
    for i in range(0, n):
        while right < i and sums[i]-sums[right] >= b:
            heapq.heappush(heap, (-f[right], right))
            right += 1
        while heap and sums[i] - sums[heap[0][1]] > a:
            heapq.heappop(heap)

        if heap: f[i] = 1 - heap[0][0]
        else: f[i] = 1
        best = max(best, f[i])

    return best


n, k = map(int, input().split())
a = list(map(int, input().split()))

sums = [0]
for x in a: sums.append(sums[-1]+x)

best = 1<<60
for i in range(n):
    for j in range(i):
        b = sums[i]-sums[j]
        lo, hi = b-1, min(best+b, sums[n-1])

        if visit(b, hi) < k: continue

        while lo+1 < hi:
            mid = (lo+hi)//2

            if visit(b, mid) >= k: hi = mid
            else: lo = mid

        best = min(best, hi-b)

print(best)
