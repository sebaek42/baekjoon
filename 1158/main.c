#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, K;
	int *circle;
	int out;
	int i;

	scanf("%d %d", &N, &K);
	i = 0;
	if (!(circle = malloc(sizeof(int) * N)))
		return (0);
	while (i < N)
	{
		circle[i] = i + 1;
		i++;
	}
	i = 0;
	out = K;
	printf("<");
	int j;
	int old;
	while (i < N)
	{
		if (i == N - 1)
		{
			printf("%d>", circle[out - 1]);
			break ;
		}
		else
			printf("%d, ", circle[out - 1]);
		circle[out - 1] = 0;
		j = 0;
		old = out + 1;
		while (j < K)
		{
			if (old > N)
				old = old % N;
			if (circle[old - 1] != 0)
				j++;
			old++;
		}
		out = old - 1;
		i++;
	}
	return (0);
}
