#include <stdio.h>

#define MAX 1000000000

int main()
{
	long double X;
	long double Y;
	long double Z;
	int game;
	int	rate;
	int	new;
	int left;
	int right;
	int result;


	scanf("%Lf%Lf", &X, &Y);
	rate = (Y / X * 100);
	new = rate;
	if (rate == 100 || rate == 99)
	{
		printf("-1");
		return (0);
	}
	game = 0;
	left = 0;
	right = MAX;
	while (left <= right)
	{
		game = (left + right) / 2;
		new = ((Y + game) * 100 / (X + game));
		if (rate >= new) {
			left = game + 1;
			result = left;
		}
		else
			right = game - 1;
	}
	printf("%d", result);
}
