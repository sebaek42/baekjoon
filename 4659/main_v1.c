#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	get_line(char **s)
{
	if (!((*s) = malloc(sizeof(char) * 21)))
		return ;
	scanf("%s", *s);
}

int		is_end(char *s)
{
	if (s[0] == 'e' && s[1] == 'n' && s[2] =='d' && s[3] == '\0')
		return (1);
	else
		return (0);
}
int		is_moeum(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return (1);
	else
		return (0);
}

int		check_line(char *s)
{
	int len;
	int i;
	int flag_aeiou;

	i = 0;
	len = strlen(s);
	while (i < len)
	{
		if (is_moeum(s[i]))
			flag_aeiou = 1;
		if (s[i + 1])
		{
			if (s[i] == s[i + 1])
			{
				if (!(s[i] == 'e' || s[i] == 'o'))
					return (0);
			}
			if (s[i + 2])
			{
				if (is_moeum(s[i]) == is_moeum(s[i+1]) && is_moeum(s[i]) == is_moeum(s[i + 2]))
					return (0);
			}
		}
		i++;
	}
	if (flag_aeiou == 1)
		return (1);
	else
		return (0);
}

void	print_line(char *s, int result)
{
	if (result == 1)
	{
		printf("<%s> is acceptable.\n", s);
	}
	else
		printf("<%s> is not acceptable.\n", s);
}

int		main(void)
{
	char *s;
	get_line(&s);
	while (!(is_end(s)))
	{
		print_line(s, check_line(s));
		free(s);
		s = NULL;
		get_line(&s);
	}
	free(s);
	s = NULL;
	return (0);
}
