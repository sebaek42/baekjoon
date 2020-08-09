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
