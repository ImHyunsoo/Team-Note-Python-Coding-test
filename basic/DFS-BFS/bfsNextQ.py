from collections import deque
import time
d = [0] * 300000001


def bfs(x):
    cnt = 0
    q = deque()
    q.append(x)
    next_q = deque()
    while True:
        while q:
            x = q.popleft()
            if x == 1:
                global m
                if m > cnt:
                    m = cnt
                return
            if d[x] == 1:
                continue
            d[x] = 1
            if x % 5 == 0:
                next_q.append(x//5)
            if x % 3 == 0:
                next_q.append(x//3)
            if x % 2 == 0:
                next_q.append(x//2)
            next_q.append(x-1)

        if not next_q:
            break
        q = next_q
        next_q = deque()
        cnt += 1
    return


x = int(input())
m = x
s = time.time()
bfs(x)
print(time.time() - s)
print(m)
