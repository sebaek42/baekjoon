#include <stdio.h>
#include <stdlib.h>

int		available(int i)
{
	int one=0;
	int ten=0;
	int hun=0;

	if ((i / 100) == 0)
		return (0);
	hun = i / 100;
	ten = (i % 100) / 10;
	one = i % 10;
	if (one == ten || one == hun || ten == hun || one == 0 || ten == 0 || hun == 0)
		return (0);
	return (1);
}

void	init_case(int **nums)
{
	int i;

	if (!((*nums) = malloc(sizeof(int) * 1000)))
		return ;
	i = 0;
	while (i < 1000)
	{
		if (available(i))
			(*nums)[i] = 1;
		else
			(*nums)[i] = 0;
		i++;
	}
}

void	init_QA(int ***QA, int num)
{
	int i;
	int j;
	if (!((*QA) = malloc(sizeof(int *) * num)))
		return ;
	i = 0;
	while (i < num)
	{
		if (!((*QA)[i] = malloc(sizeof(int) * 3)))
			return ;
		scanf("%d %d %d", &(*QA)[i][0], &(*QA)[i][1], &(*QA)[i][2]);
		i++;
	}
}

int		compare(int num, int *QA)
{
	int i;
	int j;
	int ball;
	int strike;
	int number[3];
	int tmp[3];

	number[0] = num / 100;
	number[1] = (num % 100) / 10;
	number[2] = (num % 10);
	tmp[0] =  QA[0] / 100;
	tmp[1] =  (QA[0] % 100) / 10;
	tmp[2] =  (QA[0] % 10);
	i = 0;
	strike = 0;
	ball = 0;
	while (i < 3)
	{
		if (number[i] == tmp[i])
			strike++;
		j = 0;
		while (j < 3)
		{
			if (number[i] == tmp[j])
				ball++;
			j++;
		}
		i++;
	}
	ball = ball - strike;
	if (strike == QA[1] && ball == QA[2])
		return (1);
	else
		return (0);
}

int		solve_case(int **nums, int **QA, int num)
{
	int i;
	int j;
	int result;

	i = 0;
	while (i < num)
	{
		j = 123;
		while (j < 988)
		{
			if ((*nums)[j])
			{
				if (!(compare(j, QA[i])))
					(*nums)[j] = 0;
			}
			j++;
		}
		i++;
	}
	result = 0;
	j = 123;
	while(j < 988)
	{
		if ((*nums)[j] == 1)
			result++;
		j++;
	}
	return (result);
}

void	free_QA(int **QA, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		free(QA[i]);
		QA[i] = NULL;
		i++;
	}
	free(QA);
	QA = NULL;
}

int		main(void)
{
	int *nums;
	int **QA;
	int num;
	int answer;

	scanf("%d", &num);
	init_case(&nums);
	init_QA(&QA, num);
	answer = solve_case(&nums, QA, num);
	printf("%d", answer);
	free(nums);
	nums = NULL;
	free_QA(QA, num);
	return (0);
}
