dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

if __name__ == "__main__":
	n = int(input()) # number of dragoncurves. 파이썬에선 인풋을 input()으로 받나봐..그리고 그 input()을 원하는 자료형으로 감싸서 받나봐..문자열도 받을수있을까?
	data = [list(map(int, input().split())) for _ in range(n)] # for _ in range(n) n번 루프를 돌리는거같음. 근데 이게 []안에서 돌아가고있고, 그 전에 선언된 코드를 n번 돌리나봄
	connect = [[] for _ in range(n)] # [ [], [], [] ] n개수만큼 빈 2차원 리스트 생김
	for i in range(n): # n번 돌리는데,,,i가 각각의 드래곤커브 인덱스가 됨
		x, y, d, g = data[i] # data에는 인덱스마다 각 드래곤 커브의 파라미터가 리스트 형태로 들어가있음.
		connect[i].append(d) # 0세대 방향부터 넣고
		for _ in range(g): # 세대 파라미터 값 만큼 방향을 이어붙여줌
			reverse = list(reversed(connect[i])) # 이제까지의 connect[i]를 reverse 리스트를 만들어줌
			for j in reverse: # 리버스의 요소들에 접근해서
				if j + 1 == 4: # +1에서 4가 되면 0으로 바꾸고
					connect[i].append(0)
				else:
					connect[i].append(j + 1) # 4가 아니면 그냥 +1 해준걸 connect[i]에 이어붙여줌
	arr = [[False] * 101 for _ in range(101)] # for문 두번 쓸걸 이렇게 간단하게 for in으로 해결할 수 있구나..열의 요소는 리스트를 곱해주고
	for i in range(n):
		x, y, d, g = data[i]
		arr[y][x] = True
		for j in connect[i]: # connect[i]의 요소가 결국 상 하 좌 우 결정하는 인덱스값이 되는군
			x, y = x + dx[j], y + dy[j] # x, y 위치 한번씩 갱신시켜주고
			if 0 <= x <= 100 and 0 <= y <= 100: # 범위안에 들어있다면
				arr[y][x] = True # 지나간 길로 체크해준다.

	answer = 0
	for i in range(100): # 0 ~ 99 까지
		for j in range(100): # 0 ~ 99 까지
			if arr[i][j] and arr[i][j + 1] and arr[i + 1][j] and arr[i + 1][j + 1]: # 꼭지점만 체크해서 지나면 답으로 체크
				answer += 1

	print(answer)
