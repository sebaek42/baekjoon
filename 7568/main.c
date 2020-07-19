#include <stdio.h>
#include <stdlib.h>

typedef struct	t_size
{
	int	w;
	int h;
	int rank;
}				s_size;

void	init_size(s_size **list, int len)
{
	int i;

	i = 0;
	if (!(*list = malloc(sizeof(s_size) * len)))
		return ;
	while (i < len)
	{
		scanf("%d %d", &(*list)[i].w, &(*list)[i].h);
		(*list)[i].rank = 1;
		i++;
	}
}

void	solve_size(s_size **list, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (i != j)
			{
				if ((*list)[i].w < (*list)[j].w && (*list)[i].h < (*list)[j].h)
					(*list)[i].rank += 1;
			}
			j++;
		}
		i++;
	}
}

void	print_size(s_size *list, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("%d", list[i].rank);
		i++;
		if (i < len)
			printf(" ");
	}
}

int main()
{
	s_size	*list;
	int		len;

	scanf("%d", &len);
	init_size(&list, len);
	solve_size(&list, len);
	print_size(list, len);
	return (0);
}
