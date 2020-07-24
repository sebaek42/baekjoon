#include <stdio.h>
#include <string.h>
 
int main(void)
{
	char str[101] = { NULL };
	int i;
	int len;
	int result;

	scanf("%s", str);

	i = 0;
	len = strlen(str);
	result = 0;
	while ( i < len)
	{
		if (str[i] == 'c') {
			if (str[i + 1] == '=' || str[i + 1] == '-')
				i++;
		}
		else if (str[i] = 'd')
		{
			if (str[i + 1] == '-')
				i++;
			else if (str[i + 1] == 'z' && str[i + 2] == '=')
				i = i + 2;
		}
		else if (str[i] == 'l' && str[i + 1] == 'j')
			i++;
		else if (str[i] == 'n' && str[i + 1] == 'j')
			i++;
		else if (str[i] == 's' && str[i + 1] == '=')
			i++;
		else if (str[i] == 'z' && str[i + 1] == '=')
			i++;
		i++;
		result++;
	}
	printf("%d", result);
}
