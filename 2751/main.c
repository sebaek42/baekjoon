#include <stdio.h>
#include <stdlib.h>

void	swap(int **array, int a, int b)
{
	int tmp;

	tmp = (*array)[a];
	(*array)[a] = (*array)[b];
	(*array)[b] = tmp;
}

// 인덱스를 지정한 퀵소팅은 시간초과에서 걸림. 하나씩 비교해서 교체해주기때문
// void	qsort_array(int left, int right, int **array)
// {
// 	int pivot = left;
// 	int j = pivot;
// 	int i = pivot + 1;

// 	if (left < right)
// 	{
// 		while (i <= right)
// 		{
// 			if ((*array)[pivot] > (*array)[i])
// 			{
// 				j++;
// 				swap(array, j, i);
// 			}
// 			i++;
// 		}
// 		swap(array, pivot, j);
// 		pivot = j;
// 		qsort_array(left, pivot-1, array);
// 		qsort_array(pivot+1, right, array);
// 	}
// }

int compare(const void *a, const void *b)
{
	if (*(int *)a > *(int *)b)
		return (1);
	else if (*(int *)a < *(int *)b)
		return (-1);
	else
		return (0);
}

void	print_array(int *array, int N)
{
	int i = 0;

	while (i < N)
	{
		printf("%d", array[i]);
		i++;
		if (i < N)
			printf("\n");
	}
}

int main(void)
{
	int N;
	int i;
	int *array;

	scanf("%d", &N);
	if (!(array = malloc(sizeof(int) * N)))
		return (0);
	i = 0;
	while (i < N)
	{
		scanf("%d", &array[i]);
		i++;
	}
	qsort(array, N, sizeof(int), compare);
	print_array(array, N);
	free(array);
	return (0);
}
