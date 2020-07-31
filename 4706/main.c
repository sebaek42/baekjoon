#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIGHT 299792458

typedef struct	s_list
{
	double V;
	double A;
	double B;
	struct s_list *next;
}				t_list;

void	init_list(t_list *list)
{
	while (1)
	{
		if (!(list->next = malloc(sizeof(t_list))))
			return ;
		scanf("%lf %lf", &list->A, &list->B);
		if (list->A == 0 && list->B == 0)
		{
			list->next = NULL;
			break ;
		}
		list = list->next;
	}
}

void	get_V(t_list *list)
{
	double r;
	double tmp;


	r = list->B / list->A;
	tmp = (LIGHT * (1 - (r * r))) * LIGHT; // 연산 순서 중요.
	list->V = sqrt(tmp);
	list->V = list->V / LIGHT;
}

void	solve_list(t_list *list)
{
	while (list->next != NULL)
	{
		get_V(list);
		list = list->next;
	}
}

void	print_list(t_list *list)
{
	while (list->next != NULL)
	{
		printf("%.3lf", list->V);
		list = list->next;
		if (list != NULL)
			printf("\n");
	}
}

void	free_list(t_list *list)
{
	t_list *tmp;

	list = list->next;
	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = NULL;
		list = tmp;
	}
	free(list);
	list = NULL;
}

void	main_loop(void)
{
	t_list list;

	init_list(&list);
	solve_list(&list);
	print_list(&list);
	free_list(&list);
}

int main()
{
	main_loop();
	return (0);
}
