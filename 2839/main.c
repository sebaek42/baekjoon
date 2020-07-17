#include <stdio.h>

int main(void)
{
	int N, F, T;
	int left;

	scanf("%d", &N);
	F = N / 5;
	T = (N - (5 * F)) / 3;
	left = N % (5 * F + 3 * T);
	if (left)
	{
		while (F)
		{
			left += 5;
			--F;
			if (left % 3 == 0)
			{
				T += (left / 3);
				printf("%d", F + T);
				return (0);
			}
		}
	}
	else
	{
		printf("%d", F + T);
		return (0);
	}
	printf("-1");
	return (0);
}
