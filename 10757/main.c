#include <stdio.h>
#include <string.h>
#define atoi(X) (X==0?0:X-'0')

void	reverse(char *array, int len)
{
	char tmp;
	int i;

	i = 0;
	while (i < len / 2)
	{
		tmp = array[i];
		array[i] = array[len - 1 -i];
		array[len - 1 - i] = tmp;
		i++;
	}
	return ;
}

char *add(char *A, char *B, char *S)
{
	int len;
	int carry;
	int i;

	if (strlen(A) > strlen(B))
		len = strlen(A);
	else
		len = strlen(B);
	reverse(A, strlen(A));
	reverse(B, strlen(B));
	i = 0;
	carry = 0;
	while (i <= len)
	{
		S[i] = atoi(A[i]) + atoi(B[i]) + carry;
		if (S[i] >= 10)
		{
			S[i] = S[i] - 10 + '0';
			carry = 1;
		}
		else
		{
			S[i] = S[i] + '0';
			carry = 0;
		}
		i++;
	}
	if (S[len] == '0')
		S[len] = 0;
	reverse(S, strlen(S));
	return S;
}

int main()
{
	char A[100000];
	char B[100000];
	char S[100000];
	scanf("%s %s", A, B);
	add(A, B, S);
	printf("%s", S);
	return (0);
}
