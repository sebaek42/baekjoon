## 문제

도현이의 집 N개가 수직선 위에 있다. 각각의 집의 좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 일은 없다.

도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치하려고 한다. 최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에, 한 집에는 공유기를 하나만 설치할 수 있고, 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.

C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.

## 입력

첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다. 둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi (1 ≤ xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.

## 출력

첫째 줄에 가장 인접한 두 공유기 사이의 최대 거리를 출력한다.

## 예제 입력 1

```
5 3
1
2
8
4
9

```

## 예제 출력 1

```
3
```

# 접근방법

가장 인접한 두 공유기 사이의 거리가 최대이길 바란다..

모든 공유기 사이의 거리가 공평 하길 바란다

이분탐색으로 이걸 풀수있다?

- left 는 가능한 최소거리 (left = 1)
- right 는 가능한 최대거리 (right = home[N -1] - home[0])
- distance 는 거리 ( 초기값 0. distance = home[i] - start)
- 이분탐색 반복루프조건 ( while (left ≤ right))

반복문 속에서 '기준거리'를 left와right의 중간길이로 잡고 기준 거리 내에 집이 있다면 일단 공유기를 설치한다. 그렇게 공유기를 쭉 설치해두고나서, 설치한 공유기개수가 주어진 입력보다 많거나 같다면 가능한 최소거리의 조건을 mid + 1 로 설정한다. 공유기 개수보다 적다면 가능한 최대거리를 mid - 1 로 설정한다.

그렇게 조정된 값이 left ≤ right에서 걸러지면 답을 낼수 있도록 한다 

# 코드

```c
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	int x;
	int y;

	x = *(int *)a;
	y = *(int *)b;
	if (x > y)
		return 1; // 스위치해줘야하면 1
	else if (x < y)
		return -1; // 스위치할필요없으면 -1
	else
		return 0; // 같으면 0
}

int main()
{
	int N, C;
	int home[200000] = {0};
	int i;

	scanf("%d %d", &N, &C);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &home[i]);
	}
	qsort(home, N, sizeof(int), compare);
	int left = 1; // 가능한 최소거리
	int right = home[N - 1] - home[0]; // 가능한 최대거리
	int distance = 0;
	int answer = 0;

	while (left <= right) {
		int mid = (left + right) / 2; // 기준거리
		int start = home[0];
		int cnt = 1;

		for (i = 1; i < N; i++) { //간격을 기준으로 공유기 설치
			distance = home[i] - start;
			if (mid <= distance) {
				cnt++; // 공유기 설치
				start = home[i];
			}
		}
		if (cnt >= C) { // 설치한 공유기가 설치할 공유기보다 많거나 같다면, 
			answer = mid; // 답은 mid(거리를 물어본거니까)
			left = mid + 1; // 최소거리를 mid + 1로 조정해서 while조건에 걸리는지 확인
		} else {
			right = mid - 1;
		}
	}
	printf("%d", answer);
}
```
