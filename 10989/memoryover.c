#include <stdio.h>
#include <stdlib.h>

void	init(int **list, int N)
{
	int i;

	i = 0;
	while (i < N)
	{
		scanf("%d", &(*list)[i]);
		i++;
	}
}

int		compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;
	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;
	return 0;
}

void	print_list(int *list, int N)
{
	int i = 0;

	while (i < N)
	{
		printf("%d", list[i]);
		i++;
		if (i < N)
			printf("\n");
	}
}

int main()
{
	int N;
	int *list;

	scanf("%d", &N);
	if (!(list = malloc(sizeof(int) * N)))
		return (-1);
	init(&list, N);
	qsort(list, N, sizeof(int), compare);
	print_list(list, N);
	free(list);
}
