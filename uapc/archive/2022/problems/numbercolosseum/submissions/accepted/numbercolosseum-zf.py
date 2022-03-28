#! /usr/bin/python3

input()

stack = []
for x in map(int, input().split()):
    while True:
        if x == 0:
            break
        if not stack or stack[-1]*x > 0:
            stack.append(x)
            break
        x += stack.pop()

if not stack:
    print("Tie!")
elif stack[-1] < 0:
    print("Negatives win!")
    print(*stack)
else:
    print("Positives win!")
    print(*stack)
