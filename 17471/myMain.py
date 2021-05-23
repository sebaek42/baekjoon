# input()으로 그냥 받으면 반복문속에서 입력받을때 시간초과 받을수있음
# 따라서 sys.stdin.readline()을 쓰기위해 sys를 import 한다
import sys

# 양방향 큐를 사용하기위함
from collections import deque

# 양의 무한대 math.inf가져오려구
import math

# 조합 함수를 사용하려고
from itertools import combinations

n = int(sys.stdin.readline())
populations = list(map(int, sys.stdin.readline().split()))
populations.insert(0,0)
maps = [[0 for _ in range(n+1)] for _ in range(n+1)]

for y in range(1, n+1):
	adj_list = list(map(int, sys.stdin.readline().split()))
	for x in adj_list[1:]:
		maps[y][x] = 1

max_value = math.inf

def is_group(candidates):
	queue = deque()
	queue.append(candidates[0])
	count = 1
	visited = set()
	while queue:
		y = queue.popleft()
		visited.add(y)
		for x in range(len(maps[y])):
			if maps[y][x] == 1 and x in set(candidates) and x not in visited:
				queue.append(x)
				visited.add(x)
				count += 1
	if count == len(set(candidates)):
		return True
	return False

for i in range(1, (n // 2 + 1)):
	candidates = combinations(range(1, n+1), i)
	for one in candidates:
		one = list(one)
		other = list(set(range(1, n+1)) - set(one))
		if is_group(one) is True and is_group(other) is True:
			one_value = [populations[i] for i in one]
			other_value = [populations[i] for i in other]
			max_value = min(max_value, abs(sum(one_value) - sum(other_value)))

if max_value == math.inf:
	print(-1)
else:
	print(max_value)
