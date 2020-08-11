#include <stdio.h>

int	solve(int arr[], int N, int M)
{
	int sum;
	int left;
	int right;
	int count;

	left = 0;
	right = 0;
	count = 0;
	sum = 0;
	while (1) {
		if (sum >= M)
			sum -= arr[left++];
		else if (right == N)
			break;
		else
			sum += arr[right++];
		if (sum == M)
			count++;
	}
	return count;
}

int main()
{
	int N;
	int M;
	int arr[10000];
	int i = 0;

	scanf("%d %d", &N, &M);
	while (i < N)
	{
		scanf("%d", &arr[i]);
		i++;
	}
	printf("%d", solve(arr, N, M));
}
