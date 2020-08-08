## 문제

그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

## 입력

첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

## 출력

첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

## 예제 입력 1

```
4 5 1
1 2
1 3
1 4
2 4
3 4

```

## 예제 출력 1

```
1 2 4 3
1 2 3 4

```

## 예제 입력 2

```
5 5 3
5 4
5 2
1 2
3 4
3 1

```

## 예제 출력 2

```
3 1 2 5 4
3 1 4 2 5

```

## 예제 입력 3

```
1000 1 1000
999 1000

```

## 예제 출력 3

```
1000 999
1000 999
```

# 접근방법

각 정점간 연결은 인접행렬로 표현한다. DFS, BFS탐색으로 한번 탐색한 정점을 표시하기위해 배열을 하나씩 선언해준다.

```c
int Graph[1001][1001] = {0};
int DFSA[1001] = {0};
int BFSA[1001] = {0};
int queue[1001];
```

## DFS

```c
void	DFS(int V, int N)
{
	int i;

	DFSA[V] = 1;
	printf("%d ", V);
	for(i = 1; i <= N; i++)
	{
		if (Graph[V][i] == 1 && DFSA[i] == 0) // 연결되어있고 방문하지않았다면
		{
			DFS(i, N);
		}
	}
}
```

## BFS

```c
void	BFS(int V, int N)
{
	int front = 0;
	int rear = 0;
	int pop;
	int i;

	printf("%d ", V);
	queue[0] = V;
	rear++;
	BFSA[V] = 1;
	while (front < rear)
	{
		pop = queue[front];
		front++;
		for (i = 1; i <= N; i++)
		{
			if (Graph[pop][i] == 1 && BFSA[i] == 0)
			{
				printf("%d ", i);
				queue[rear] = i;
				rear++;
				BFSA[i] = 1;
			}
		}
	}
	return ;
}
```

```c
int main()
{
	int N, M, V;
	int i;
	int x, y;

	scanf("%d%d%d", &N, &M, &V);
	for (i = 0; i < M; i++)
	{
		scanf("%d%d", &x, &y);
		Graph[x][y] = 1;
		Graph[y][x] = 1;
	}
	DFS(V, N);
	printf("\n");
	BFS(V, N);
	return (0);
}
```
