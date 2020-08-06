#include <stdio.h>

void	check(int board[][5], int tmp)
{
	int i;
	int j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			if (board[i][j] == tmp)
			{
				board[i][j] = 0;
			}
			j++;
		}
		i++;
	}
}

int		bingo(int board[][5])
{
	int i = 0;
	int j = 0;
	int bingo = 0;
	int rowcount;
	int colcount;
	int ldiagonal;
	int udiagonal;

	ldiagonal = 0;
	udiagonal = 0;
	while (i < 5)
	{
		j = 0;
		rowcount = 0;
		colcount = 0;
		while (j < 5)
		{
			if (board[i][j] == 0)
			{
				rowcount++;
			}
			if (board[j][i] == 0)
			{
				colcount++;
			}
			if ((i == j) && board[i][j] == 0 )
			{
				ldiagonal++;
			}
			if ((i + j == 4) && board[i][j] == 0)
			{
				udiagonal++;
			}
			j++;
		}
		if (rowcount == 5)
		{
			bingo++;
		}
		if (colcount == 5)
		{
			bingo++;
		}
		if (ldiagonal == 5)
		{
			bingo++;
		}
		if (udiagonal == 5)
		{
			bingo++;
		}
		if (bingo == 3)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int main()
{
	int board[5][5];
	int tmp[25];
	int count;
	int i;
	int j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			scanf("%d", &board[i][j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 25)
	{
		scanf("%d", &tmp[i]);
		i++;
	}
	count = 0;
	while (count < 25)
	{
		check(board, tmp[count]);
		count++;
		if (bingo(board))
			break;
	}
	printf("%d", count);
}
