#include <stdio.h>
#include <stdlib.h>

typedef struct t_info
{
	int index;
	int age;
	char *name;
} s_info;

void	init_info(s_info **list, int len)
{
	int i;

	i = 0;
	if (!((*list) = malloc(sizeof(s_info) * len)))
		return ;
	while (i < len)
	{
		if (!((*list)[i].name = malloc(sizeof(char) * 101)))
			return ;
		scanf("%d %s",&(*list)[i].age, (*list)[i].name);
		(*list)[i].index = i;
		i++;
	}
}

void	swap_info(s_info **list, int a, int b)
{
	s_info tmp;

	tmp.age = (*list)[a].age;
	tmp.name = (*list)[a].name;
	tmp.index = (*list)[a].index;
	(*list)[a].age = (*list)[b].age;
	(*list)[a].name = (*list)[b].name;
	(*list)[a].index = (*list)[b].index;
	(*list)[b].age = tmp.age;
	(*list)[b].name = tmp.name;
	(*list)[b].index = tmp.index;
}

/**  이정렬은 시간초과남.
void	sort_info(s_info **list, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if ((*list)[j].age > (*list)[j + 1].age)
				swap_info(list, j, j + 1);
			else if ((*list)[j].age == (*list)[j + 1].age)
			{
				if ((*list)[j].index > (*list)[j + 1].index)
					swap_info(list, j, j + 1);
			}
			j++;
		}
		i++;
	}
} 
**/

//퀵소팅 사용


void	quick_sort(int left, int right, s_info **list)
{
	int i;
	int j;
	int pivot;

	pivot = left;
	j = pivot;
	i = pivot + 1;
	if (left < right)
	{
		while (i <= right)
		{
			
			if ((*list)[i].age < (*list)[pivot].age)
			{
				j++;
				swap_info(list, i, j);
			}
			else if ((*list)[i].age == (*list)[pivot].age)
			{
				if ((*list)[i].index < (*list)[pivot].index)
				{
					j++;
					swap_info(list, i, j);
				}
			}
			i++;
		}
		swap_info(list, j, pivot);
		pivot = j;
		quick_sort(left, pivot-1, list);
		quick_sort(pivot+1, right, list);
	}
}
void	sort_info(s_info **list, int len)
{
	quick_sort(0, len - 1, list);
}
	
void print_info(s_info **list, int len)
{
	int i = 0;

	while (i < len)
	{
		printf("%d %s\n", (*list)[i].age, (*list)[i].name);
		i++;
	}
}

int main(void)
{
	s_info *list;
	int len;

	scanf("%d", &len);
	init_info(&list, len);
	sort_info(&list, len);
	print_info(&list, len);
	free(list);
	list = NULL;
	return (0);
}
