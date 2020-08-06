#include <stdio.h>

int main()
{
	int x;
	unsigned int A, B, C;
	unsigned int cost;
	unsigned int profit;

	scanf("%d %d %d", &A, &B, &C);
	x = -1;
	if (B >= C)
	{
		printf("-1");
		return (0);
	}
	x = A / (C - B);
	printf("%d", x + 1);
	return (0);
}
