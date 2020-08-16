#include <stdio.h>
#include <stdlib.h>

int lower_bound(int left, int right, int value, int **b)  //
{
	while (left <= right) // 이진 탐색으로 적절한 위치를 찾아서 위치값 반환
	{
		int mid = (left + right) / 2;
		if ((*b)[mid] >= value)
			right = mid - 1;
		else
		{
			left = mid + 1;
		}
	}
	return left;
}

int main()
{
	int n;
	scanf("%d", &n);
	int *a;
	int *b;
	a = malloc(sizeof(int) * n); // 입력받을 배열
	b = malloc(sizeof(int) * n); //
	int i;
	int count;

	count = 0;
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int size = 1;
	b[0] = a[0];
	for (i = 1; i < n; i++) // 루프 한번으로 해결
	{
		if (b[size - 1] <= a[i]) // 이전게 지금값보다 작은 값이면 그대로 배열b에 복사
		{
			b[size] = a[i];
			size++;
		}
		else // 그렇지않고 지금 보는 값이 이전값보다 작은 값이라면 지금 값을 배열 b의 적절한 위치에 넣어준다
		{
			b[lower_bound(0, size - 1, a[i], &b)] = a[i];
			count++;
		}
	}
	printf("%d", count);
	return 0;
}
