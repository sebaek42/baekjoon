#include <stdio.h>

int main()
{
	int N;
	int num;
	int count[10001] = {0, };
	int i;
	int j;

	scanf("%d", &N);
	i = 0;
	while (i < N)
	{
		scanf("%d", &num);
		count[num]++;
		i++;
	}
	i = 0;
	while (i < 10001)
	{
		if (count[i] != 0)
		{
			j = 0;
			while (j < count[i])
			{
				printf("%d\n", i);
				j++;
			}
		}
		i++;
	}
	return 0;
}
