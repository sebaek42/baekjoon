#include <stdio.h>

int main(void)
{
	int A, B, V;
	int days;
	
	scanf("%d %d %d", &A, &B, &V);
	days = (V - B - 1) / (A - B) + 1;
	printf("%d", days);
	return (0);
}
