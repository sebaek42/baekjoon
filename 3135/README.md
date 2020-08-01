링크: [https://www.acmicpc.net/problem/3135](https://www.acmicpc.net/problem/3135)

## 문제

준하는 라디오 수집광으로 신제품의 라디오가 나올때마다 흥분을 금치 못한다고 한다.

최근 준하가 구입한 라디오는 매우 하이테크 한데, 그 라디오에는 다음과 같은 버튼이 있다.

- 첫 번째 버튼은 주파수를 1MHz 증가시킨다.
- 두 번째 버튼은 주파수를 1MHz 감소시킨다.
- 나머지 N개의 버튼은 즐겨찾기 기능으로, 미리 지정된 주파수로 이동한다.

준하는 몸이 안좋아 하루에 손가락을 몇 번 움직이지 못하기 때문에 우리의 도움이 필요하다.

현재 주파수 A와 듣고싶은 주파수 B가 주어질 때,

주파수 A에서 B로 갈 때 눌러야 하는 가장 적은 버튼수를 구해주자.

## 입력

첫 줄엔 정수 A와 B가 주어진다 (1 ≤ A, B < 1000, A ≠ B).

다음 줄엔 정수 N이 주어진다 (1 ≤ N ≤ 5).

다음 N개의 줄엔 미리 지정되어 있는 주파수가 주어진다 (주파수는 1000 보다 작다).

## 출력

주파수 A에서 B로 갈 때 눌러야 하는 버튼수의 최솟값을 출력한다.

## 예제 입력 1

```
88 17
3
18
1
42

```

## 예제 출력 1

```
2
```

# 접근방법

A 에서 B로 갈때 누를수있는 최소 버튼 횟수를 구해야한다. 입력에서 몇개의 저장된 주파수가 들어올지 전달되기 때문에 배열 포인터를 동적할당해서 즐겨찾기 버튼을 저장했다.

A와 배열에 저장된 값들중 B와의 거리가 가장 가까운곳을 찾아낸뒤 가장 가까운곳이 A라면 카운트를 세지않고, 가장 가까운곳이 즐겨찾기에 있다면 카운트를 하나 센뒤, 그곳에서부터 B까지 가기위해 올라가거나 내려가거나를 몇번 반복해야하는지를 구했다.

# 코드

```jsx
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		get_distance(int a, int b)
{
	return (a > b ? (a - b) : (b - a));
}

int		get_closest(int A, int B, int N, int *mark)
{
	int i;
	int distance;
	int closest;

	i = 0;
	closest = A;
	distance = get_distance(A, B);
	while (i < N)
	{
		if (distance > get_distance(mark[i], B))
		{
			distance = get_distance(mark[i], B);
			closest = mark[i];
		}
		i++;
	}
	return closest;
}

int		solution(int A, int B, int N, int *mark)
{
	int D;
	int count;
	int closest;
	int direction;

	count = 0;
	closest = get_closest(A, B, N, mark);
	if (closest == A)
		count = 0;
	else
		count = 1;
	if (closest > B)
		direction = -1;
	else
		direction = 1;
	while (closest != B)
	{
		closest = closest + direction;
		count++;
	}
	return (count);
}
void	init_mark(int **mark, int N)
{
	int i = 0;

	while (i < N)
	{
		scanf("%d", &(*mark)[i]);
		i++;
	}
}

int main(void)
{
	int A, B;
	int N;
	int *mark;

	scanf("%d %d", &A, &B);
	scanf("%d", &N);
	if (!(mark = malloc(sizeof(int) * N)))
		return (-1);
	init_mark(&mark, N);
	printf("%d", solution(A, B, N, mark));
	free(mark);
	return (0);
}
```

# 생각해보기

위 코드는 카운터를 두고 카운터를 반복문에서 하나씩 증가시키고있다. 그냥 그럴 필요없이 A에서 시작하는지 즐겨찾기에 저장된 곳에서 시작하는지 판별하고 그곳에서 부터 B까지의 거리를 구하면 자연스럽게 결과값을 낼수 있을 것 같다. 시간 복잡도를 훨씬 줄일 수 있는 부분일것이다.
