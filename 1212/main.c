#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char tmp[333334];
	char a[3];
	int i;
	int j;
	int T;
	int len;
	int cnt;

	cnt = 0;
	scanf("%s", tmp);
	len = strlen(tmp);
	i = 0;
	while (i < len)
	{
		j = 2;
		T = tmp[i] - '0';
		while (j >= 0)
		{
			if (T % 2)
				a[j] = '1';
			else
				a[j] = '0';
			T = T / 2;
			j--;
		}
		if (cnt == 0)
		{
			if (a[0] == '0')
			{
				if (a[1] == '0')
				{
					if (a[2] == '0')
						printf("0");
					else
						printf("1");
				}
				else
				{
					printf("%c", a[1]);
					printf("%c", a[2]);
				}
			}
			else
			{
				printf("%c", a[0]);
				printf("%c", a[1]);
				printf("%c", a[2]);
			}
		}
		else
		{
			printf("%c", a[0]);
			printf("%c", a[1]);
			printf("%c", a[2]);
		}
		cnt++;
		i++;
	}
}
