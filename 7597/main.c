#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_list
{
	char			*content;
	int				score_A;
	int				score_B;
	struct s_list	*next;
}				t_list;

void	init_list(t_list *list)
{
	char tmp[250];

	while (1)
	{
		scanf("%s", tmp);
		if (tmp[0] == '#')
			break ;
		list->content = strdup(tmp);
		list->score_A = 0;
		list->score_B = 0;
		if (!(list->next = malloc(sizeof(t_list))))
			return ;
		list = list->next;
	}
	list = NULL;
}

void	get_score(t_list *list)
{
	int i;
	int A;
	int B;

	i = 0;
	A = 0;
	B = 0;
	while (list->content[i])
	{
		if (list->content[i] == 'A')
			++A;
		else if (list->content[i] == 'B')
			++B;
		if ((A >= 4 || B >= 4) && ((A - B) >= 2 || (B - A) >= 2))
		{
			if (A - B >= 2)
				list->score_A++;
			if (B - A >= 2)
				list->score_B++;
			A = 0;
			B = 0;
		}
		i++;
	}
}

void	solve_list(t_list *list)
{
	while (list->next != NULL)
	{
		get_score(list);
		list = list->next;
	}
}

void	print_list(t_list *list)
{
	while (list->next != NULL)
	{
		printf("A %d B %d", list->score_A, list->score_B);
		list = list->next;
		if (list != NULL)
			printf("\n");
	}
}

int main()
{
	t_list list;

	init_list(&list);
	solve_list(&list);
	print_list(&list);
}
