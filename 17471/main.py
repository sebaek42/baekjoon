import sys
from collections import deque
import math
from itertools import combinations

n = int(sys.stdin.readline()) # 선거구들의 수 받고
populations = list(map(int, sys.stdin.readline().split())) # 각 선거구의 인구수 리스트로 받고
populations.insert(0,0) # 인덱스로 접근이아니라 선거구 번호로 접근하는걸 생각하기 쉽게 하려고 0번째 리스트에 0 값 삽입

maps = [[0 for _ in range(n+1)] for _ in range(n+1)] # 여기도 인덱스 접근이 아니라 선거구 번호로 접근하려고 n+1로

for y in range(1, n+1): # 1번째부터
	adj_list = list(map(int, sys.stdin.readline().split()))
	for x in adj_list[1:]: # 0번째 숫자는 인접한 구역의 수 이므로 지도에 직접 들어갈 정보가 아님. 제외한 나머지 숫자를 좌표로 담아줌
		maps[y][x] = 1

max_value = math.inf # math.infinity 양의 무한대

def is_group(start, maps, candidates):
	queue = deque() # 양방향 큐가 바로 데크. 앞 뒤 양쪽 방향에서 엘리먼트 추가 삭제 가능 from collections import deque
	queue.append(start)
	count = 1
	visited = set()
	while queue:
		y = queue.popleft() # 맨 앞요소 가져오는동시에 덱에서 삭제
		visited.add(y) # 방문기록 남기고
		for x in range(len(maps[y])): # 해당 행의 열을 검사
			if maps[y][x] == 1 and x in candidates and x not in visited:
				queue.append(x)
				visited.add(x)
				count += 1
	if count == len(candidates):
		return True
	return False


for i in range(1, (n // 2 + 1)): # 조합의 원소최대 크기는 n / 2 의 몫이므로..파이썬에선 몫연산은 n // 2 로구함. 끝숫자는 포함하지 않으므로 + 1 로 끝 숫자 늘려줌
	candidates = combinations(range(1, n+1), i) # 조합을 뽑아냄. 1 ~ n의 선거구중 1 ~ n/2개로 이뤄진.
	for one in candidates:
		one = list(one)
		other = list(set(range(1, n+1)) - set(one))
		if is_group(one[0], maps, set(one)) is True and is_group(other[0], maps, set(other)) is True:
			one_value = [populations[i] for i in one]
			other_value = [populations[i] for i in other]
			max_value = min(max_value, abs(sum(one_value) - sum(other_value)))

if max_value == math.inf:
	print(-1)
else:
	print(max_value)
