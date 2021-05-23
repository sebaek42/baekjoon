n, m = map(int, input().split())

result = -1
for i in range(n):
	data = map(int, input().split())
	min_value = min(data)
	if min_value > result:
		result = min_value
print(result)
