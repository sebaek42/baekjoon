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
