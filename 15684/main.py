import sys


def dfs(cnt, idx, r):
	global ans
	if cnt == r:
		if move():
			ans = cnt
		return
	for i in range(idx, h):
		for j in range(n - 1):
			if a[j][i]:
				continue
			if j - 1 >= 0 and a[j-1][i]:
				continue
			?

# N: 세로선의 수 M: 가로선의 수 H: 세로선마다 가로선을 넣을 위치의 수
n, m, h = map(int, sys.stdin.readline().split())
# M이 그어진 가로선의 수니까 이 수 만큼 입력을 더 받겠다는 거지. 연결한 점선의 가로위치, 세로선의 위치
a = [[0] * h for _ in range(n)]
for _ in range(m): # 선 그어주는걸 점을 1로 바꾸는거로 표현
	x, y = map(int, input().split())
	a[y - 1][x - 1] = 1

 ans, flag = sys.maxsize, 1
 for r in range(4):
	 dfs(0, 0, r)
	 if ans != sys.maxsize:
		 print(ans)
		 flag = 0
		 break
if flag:
	print(-1)
