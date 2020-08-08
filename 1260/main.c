#include <stdio.h>

int Graph[1001][1001] = {0};
int DFSA[1001] = {0};
int BFSA[1001] = {0};
int queue[1001];

// 이차원 배열 -> 인덱스와 인덱스교점이 1 = 연결됨 0 = 연결안됨

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
