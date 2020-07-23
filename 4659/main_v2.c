#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_list
{
	char		*content;
	int			result;
	struct		s_list *next;
}				t_list;



int		is_end(char *s)
{
	if (s[0] && s[1] && s[2])
	{
		if (s[0] == 'e' && s[1] == 'n' && s[2] =='d' && s[3] == '\0')
			return (1);
	}
	return (0);
}

int		is_moeum(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return (1);
	else
		return (0);
}

void		check_line(t_list *list)
{
	int len;
	int i;
	int flag_aeiou;

	i = 0;
	flag_aeiou = 0;
	if (is_end(list->content))
	{
		list->result = -1;
		return ;
	}
	len = strlen(list->content);
	while (i < len)
	{
		if (is_moeum(list->content[i]))
			flag_aeiou = 1;
		if (list->content[i + 1])
		{
			if (list->content[i] == list->content[i + 1])
			{
				if (!(list->content[i] == 'e' || list->content[i] == 'o'))
				{
					list->result = 0;
					return ;
				}
			}
			if (list->content[i + 2])
			{
				if (is_moeum(list->content[i]) == is_moeum(list->content[i+1]) && is_moeum(list->content[i]) == is_moeum(list->content[i + 2]))
				{
					list->result = 0;
					return ;
				}
			}
		}
		i++;
	}
	if (flag_aeiou == 1)
	{
		list->result = 1;
		return ;
	}
	list->result = 0;
	return ;
}

void	print_list(t_list *list)
{
	while (list->next != NULL)
	{
		if (list->result == 1)
			printf("<%s> is acceptable.\n", list->content);
		else if (list->result == 0)
			printf("<%s> is not acceptable.\n", list->content);
		list = list->next;
	}
}

void	init_list(t_list **list)
{
	if (!((*list) = malloc(sizeof(t_list))))
		return ;
	if (!(((*list)->next) = malloc(sizeof(t_list))))
		return ;
	if (!((*list)->content = malloc(sizeof(char) * 21)))
		return ;
	(*list)->result = 0;
	scanf("%s", (*list)->content);
}

void	add_list(t_list **list)
{
	(*list) = (*list)->next;
	if (!(((*list)->next) = malloc(sizeof(t_list))))
		return ;
	if (!((*list)->content = malloc(sizeof(char) * 21)))
		return ;
	(*list)->result = 0;
	scanf("%s", (*list)->content);
}

void	free_list(t_list *list)
{
	t_list *tmp;

	while (list->next != NULL)
	{
		tmp = list->next;
		free(list->content);
		list->content = NULL;
		free(list);
		list = tmp;
	}
	free(list->content);
	free(list->next);
	free(list);
	list = NULL;
}

int		main(void)
{
	t_list *list;
	t_list *tmp;

	init_list(&list); //TODO: initialize list. malloc, get first input by scanf
	check_line(list);
	tmp = list;
	while (!(is_end(list->content)))
	{
		add_list(&list); //TODO: list = list->next and get input, malloc another list for next
		check_line(list);
	}
	list->next = NULL;
	print_list(tmp);
	free_list(tmp);

	while (1)
	{
	}
	return (0);
}
