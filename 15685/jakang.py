import copy

n = int(input())
arr = [[0] * 101 for _ in range(101)]

dx = [0, -1, 0, 1]
dy = [1, 0, -1, 0]

for i in range(n):
    y, x, d, g = map(int, input().split())
    q = [d]
    arr[x][y] = 1
    x = x + dx[d]
    y = y + dy[d]
    arr[x][y] = 1
    for j in range(g):
        rq = copy.deepcopy(q)
        rq.reverse()
        nq = []
        for k in rq:
            x = x + dx[(k + 1) % 4]
            y = y + dy[(k + 1) % 4]
            arr[x][y] = 1
            nq.append((k + 1) % 4)
        q += nq

ans = 0
for i in range(100):
    for j in range(100):
        if arr[i][j] and arr[i][j + 1] and arr[i + 1][j] and arr[i + 1][j + 1]:
            ans += 1

print(ans)
