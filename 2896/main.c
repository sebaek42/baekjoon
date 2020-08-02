#include <stdio.h>
#include <stdlib.h>

double get_num(double A, double B, double C, double I, double J, double K)
{
	double a, b, c;

	a = A / I;
	b = B / J;
	c = C / K;
	if (a <= b && a <= c)
		return a;
	else if (b <= a && b <= c)
		return b;
	else if (c <= a && c <= b)
		return c;
	return (a);
}

int main()
{
	double A, B, C;
	double I, J, K;
	double num;

	scanf("%lf %lf %lf", &A, &B ,&C);
	scanf("%lf %lf %lf", &I, &J, &K);

	num = get_num(A, B, C, I, J, K);
	printf("%lf %lf %lf", A-(num * I), B-(num * J), C-(num * K));
	return (0);
}
