#include <stdio.h>
#include <stdlib.h>
 
char	**init_str(void)
{
	int i;
	int j;
	char **new;

	i = 0;
	new = malloc(sizeof(char *) * 101);
	while (i < 101)
	{
		j = 0;
		new[i] = malloc(sizeof(char) * 101);
		while (j < 101)
		{
			new[i][j] = 0;
			j++;
		}
		i++;
	}
	return (new);
}

int		solve_str(char **str)
{
	int i;
	int j;
	int temp;
	int result;
	int close[26] = {0,};

	i = 0;
	result = 0;
	while (*str[i])
	{
		j = 0;
		while (j < 26)
			close[j++] = 0;
		j = 0;
		while (str[i][j])
		{
			if (close[(unsigned char)str[i][j] - 'a'] == 1)
			{
				result -= 1;
				break ;
			}
			if (str[i][j] != str[i][j + 1])
				close[(unsigned char)str[i][j] - 'a'] = 1;
			j++;
		}
		result++;
		i++;
	}
	return (result);
}

void free_str(char **str)
{
	int i;
	char **tmp;

	tmp = str;
	i = 0;
	while (i < 101)
	{
		free(*str++);
		i++;
	}
	free(tmp);
}

int		main()
{
	int amount;
	int i;
	int result;
	char **str;

	i = 0;
	str = init_str();
	scanf("%d", &amount);
	while (i < amount)
		scanf("%s", str[i++]);
	result = solve_str(str);
	printf("%d", result);
	free_str(str);
	return (0);
}
	
