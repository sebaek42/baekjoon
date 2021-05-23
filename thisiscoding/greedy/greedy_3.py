n, k = map(int, input().split())
cnt = 0
while n != 1:
	if n % k:
		n -= 1
	else:
		n = n / k
	cnt += 1
print(cnt)
