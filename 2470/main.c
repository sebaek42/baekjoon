#include <stdio.h>
#include <stdlib.h>

int abs(int a)
{
	if (a < 0)
		return a * -1;
	else
	{
		return a;
	}

}

int compare(const void *a, const void *b)
{
	int x;
	int y;

	x = *(int *)a;
	y = *(int *)b;
	if (x > y)
		return 1;
	else if (x < y)
		return -1;
	else
	{
		return 0;
	}

}

int main()
{
	int n;
	int i;
	int j;
	int min;
	int ans_i;
	int ans_j;
	int v;
	int *arr;

	scanf("%d", &n);
	arr = malloc(sizeof(int) * n);
	for(i = 0; i<n; i++)
		scanf("%d", &arr[i]);
	qsort(arr, n, sizeof(int), compare);
	i = 0;
	j = n - 1;
	while (i < j)
	{
		v = arr[i] + arr[j];
		if (abs(v) <= min){
			min = abs(v);
			ans_i = i;
			ans_j = j;
		}
		if (v > 0)
			j--;
		else if (v < 0)
			i++;
		else
		{
			break ;
		}
	}
	printf("%d %d", arr[ans_i], arr[ans_j]);
}
