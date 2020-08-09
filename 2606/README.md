링크: [https://www.acmicpc.net/problem/2606](https://www.acmicpc.net/problem/2606)

## 문제

신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.

![https://www.acmicpc.net/upload/images/zmMEZZ8ioN6rhCdHmcIT4a7.png](https://www.acmicpc.net/upload/images/zmMEZZ8ioN6rhCdHmcIT4a7.png)

어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

## 출력

1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

## 예제 입력 1

```
7
6
1 2
2 3
1 5
5 2
5 6
4 7

```

## 예제 출력 1

```
4
```

# 접근방법

연결된 컴퓨터들의 개수를 구하는 문제인것 같다. DFS, BFS알고리즘을 통해 구할 수 있었다

# 코드

```c
#include <stdio.h>

int Graph[101][101] = {0};
int DFSA[101] = {0};
int BFSA[101] = {0};

void	DFS(int V, int N, int *count)
{
	int i;

	DFSA[V] = 1;
	for (i = 1; i <= N; i++)
	{
		if (Graph[V][i] == 1 && DFSA[i] == 0)
		{
			(*count) = (*count) + 1;
			DFS(i, N, count);
		}
	}
}

void	BFS(int V, int N, int *count)
{
	int i;
	int queue[101] = {0};
	int front = 0;
	int rear  = 1;
	int pop;

	queue[front] = V;
	BFSA[V] = 1;
	while (front < rear)
	{
		pop = queue[front];
		front++;
		for (i = 1; i <= N; i++)
		{
			if (Graph[pop][i] == 1 && BFSA[i] == 0)
			{
				queue[rear] = i;
				rear++;
				BFSA[i] = 1;
				(*count) = (*count) + 1;
			}
		}
	}

}

int main()
{
	int N;
	int C;
	int i;
	int x;
	int y;
	int count;

	scanf("%d%d", &N, &C);
	for(i = 0; i < C; i++)
	{
		scanf("%d%d", &x, &y);
		Graph[x][y] = 1;
		Graph[y][x] = 1;
	}
	count = 0;
	DFS(1, N, &count);
	printf("%d\n", count);
	count = 0;
	BFS(1, N, &count);
	printf("%d", count);
}
```
