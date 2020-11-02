#include <stdio.h>

int  main()
{
	int A;
	int B;
	int C;

	while (1)
	{
	scanf("%d %d %d", &A, &B, &C);
	int min;
	int mid;
	int max;
		if (A < B)
	{
		min = A;
		max = B;
	}
	else
	{
		min = B;
		max = A;
	}

	if (max < C)
	{
		mid = max;
		max = C;
	}
	else
	{
		if (min > C)
		{
			mid = min;
			min = C;
		}
		else
		{
			mid = C;
		}

	}


	printf("%d %d %d          s       ㅇ\n", min, mid, max);

	}
}
