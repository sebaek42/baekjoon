#include <stdio.h>
#include <stdlib.h>

void	init_stars(char ***stars, int N)
{
	int len;
	int i;
	int j;

	len = 4*(N - 1) + 1;
	if (!((*stars) = malloc(sizeof(char *) * len)))
		return ;
	i = 0;
	while (i < len)
	{
		if (!((*stars)[i] = malloc(sizeof(char) * len)))
			return ;
		j = 0;
		while (j < len)
		{
			(*stars)[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	fill_stars(char ***stars, int N, int col, int row)
{
	int len;
	int i;
	int j;

	len = 4 * (N - 1) + 1;
	if (N == 1)
	{
		(*stars)[row][col] = '*';
		return ;
	}
	j = col;
	while (j < col + len)
	{
		(*stars)[row][j] = '*';
		(*stars)[row + len - 1][j] = '*';
		j++;
	}
	i = row;
	while (i < row + len)
	{
		(*stars)[i][col] = '*';
		(*stars)[i][col + len - 1] = '*';
		i++;
	}
	fill_stars(stars, N - 1, col + 2, row + 2);
	return ;
}

void	print_stars(char **stars, int N)
{
	int len;
	int i;
	int j;

	len = 4 *(N - 1) + 1;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			printf("%c", stars[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int main(void)
{
	int N;
	char **stars;

	scanf("%d", &N);
	init_stars(&stars, N);
	fill_stars(&stars, N, 0, 0);
	print_stars(stars, N);
	//free_stars(stars);
}
