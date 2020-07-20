#include <stdio.h>
#include <stdlib.h>

typedef struct	s_address
{
	int			k;
	int			n;
	int			people;
}				t_address;

void	init_list(t_address **list, int T)
{
	int i;

	i = 0;
	if (!(*list = malloc(sizeof(t_address) * T)))
		return ;
	while (i < T)
	{
		scanf("%d\n%d", &(*list)[i].k, &(*list)[i].n);
		(*list)[i].people = 0;
		i++;
	}
}

int		r_solution(int k, int n)
{
	int i;
	int result;

	i = 1;
	result = 0;
	if (k >= 0)
	{

	//  f(0, n) = n;
	//	f(1, n) = f(0, 1) + f(0, 2) + ... + f(0, n);
	//	f(2, n) = f(1, 1) + f(1, 2) + ... + f(1, n);
	//			= f(0, 1) + (f(0, 1) + f(0, 2)) + ... (f(0, 1) +...+ f(0, n));
	//	f(3, n) = f(2, 1) + f(2, 2) + ... + f(2, n);
	//			. . .
	//	f(k , n) = f(k -1, 1) + f(k - 1, 2) + ... f(k - 1, n);
	//	r_solution(k, n) = r_solution(k -1, 1) + ...;
	
		if (k == 0)
		{
			i = n;
			return (i);
		}
		while (i < n + 1)
		{
			result += r_solution(k - 1, i);
			i++;
		}
		return (result);
	}
	return (0);
}

void	solve_list(t_address **list, int T)
{
	int i;

	i = 0;
	while (i < T)
	{
		(*list)[i].people = r_solution((*list)[i].k, (*list)[i].n);
		i++;
	}
}

void	print_list(t_address *list, int T)
{
	int i = 0;

	while (i < T)
	{
		printf("%d", list[i].people);
		i++;
		if (i < T)
			printf("\n");
	}
}

void	free_list(t_address *list)
{
	free(list);
	list = NULL;
}

int		main()
{
	int T;
	t_address	*list;

	scanf("%d", &T);
	init_list(&list, T);
	solve_list(&list, T);
	print_list(list, T);
	free_list(list);
	return (0);
}
