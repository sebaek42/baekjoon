#include <stdio.h>
#include <stdlib.h>

int	solve_result(int *trees, int N, int M)
{
	int i;
	int sum;
	int highest;

	i = 0;
	highest = 0;
	while (i < N)
	{
		if (trees[i] >= highest)
			highest = trees[i];
		i++;
	}
	sum = 0;
	while (highest > 0)
	{
		sum = 0;
		i = 0;
		while (i < N)
		{
			if (trees[i] > highest)
				sum = sum + trees[i] - highest;
			i++;
		}
		if (sum >= M)
			return (highest);
		highest--;
	}
	return (0);
}

int main(void)
{
	int N;
	int M;
	int *trees;
	int i;

	scanf("%d %d", &N, &M);
	if (!(trees = malloc(sizeof(int) * N)))
		return (0);
	i = 0;
	while (i < N)
		scanf("%d", &trees[i++]);
	printf("%d", solve_result(trees, N, M));
	free(trees);
	trees = NULL;
	return (0);
}
