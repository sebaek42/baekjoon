#include <stdio.h>
#include <stdlib.h>

typedef struct	t_point
{
	int	x;
	int	y;
} 		s_point;

void	swap(s_point *a, s_point *b)
{
	int x;
	int y;

	x = a->x;
	y = a->y;
	a->x = b->x;
	a->y = b->y;
	b->x = x;
	b->y = y;
}

s_point *init_points(s_point *points, int len)
{
	int i;

	if (!(points = malloc(sizeof(s_point) * len)))
		return (0);
	i = 0;
	while (i < len)
	{
		scanf("%d %d", &points[i].x, &points[i].y);
		i++;
	}
	return (points);
}

void	print_points(s_point *points, int len)
{
	int i;
	i = 0;
	while (i < len)
	{
		printf("%d %d\n", points[i].x, points[i].y);
		i++;
	}
}

void	sort(int left, int right, s_point *points)
{
	int pivot;
	int j;
	int i;

	pivot = left;
	j = pivot;
	i = left + 1;
	if (left < right)
	{
		while (i <= right)
		{
			if (points[i].y < points[pivot].y)
			{
				j++;
				swap(&points[i], &points[j]);
			}
			else if (points[i].y == points[pivot].y)
			{
				if (points[i].x < points[pivot].x)
				{
					j++;
					swap(&points[i], &points[j]);
				}
			}
			i++;
		}
		swap(&points[left], &points[j]);
		pivot = j;
		sort(left, pivot - 1, points);
		sort(pivot + 1, right, points);
	}
}

int main(void)
{
	s_point	*points;
	int	i;
	int	len;

	scanf("%d", &len);
	points = init_points(points, len);
	//TODO: sort structure points
	sort(0, len - 1, points);
	print_points(points, len);
	return (0);
}
