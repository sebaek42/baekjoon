# N, M, K 가 입력으로 주어진다. N=배열의크기, M=숫자가더해지는횟수, K=연속해서더할수있는횟수
N, M, K = map(int, input().split())
# 배열 입력
data = list(map(int, input().split()))

data.sort()
first = data[N - 1]
second = data[N - 2]

result = 0
cnt = 0
for i in range(M):
	if cnt < K:
		result += first
		cnt += 1
		i += 1
	else:
		result += second
		cnt = 0
		i += 1
print(result)

# 입력 예시
# 5 8 3
# 2 4 5 4 6
# 출력 예시
# 46
