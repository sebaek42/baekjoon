#include <stdio.h>

double solve(double A, double B, double C, int X, int Y)
{
	int num;
	int pack;
	double price;
	double result;

	if (X > Y)
	{
		num = X - Y;
		pack = 2 * Y;
		price = A;
	}
	else
	{
		num = Y - X;
		pack = 2 * X;
		price = B;
	}
	if (A + B < 2 * C)
		return (A * X + B * Y);
	else
	{
		result = pack * C + num * price;
		if (num * price > num * 2 * C)
		{
			result = (pack + num * 2) * C;
		}
		return (result);
	}
}

int main()
{
	double A, B, C;
	int X, Y;

	scanf("%lf %lf %lf %d %d", &A, &B, &C, &X, &Y);
	printf("%.lf", solve(A, B, C, X, Y));
}
