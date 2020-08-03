#include <stdio.h>

unsigned long long int solve(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (solve(n - 1) + solve(n - 2));
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%lld", solve(n));
}
