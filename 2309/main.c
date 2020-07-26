#include <stdio.h>
#include <stdlib.h>

void	get_array(int *array)
{
	int i;

	i = 0;
	//if (!((*array) = malloc(sizeof(int) * 9)))
	//	return ;
	while (i < 9)
	{
		scanf("%d", &array[i]);
		i++;
	}
}

void	print_array(int *array)
{
	int i = 0;

	while (i < 7)
	{
		printf("%d", array[i]);
		i++;
		if (i < 7)
			printf("\n");
	}
}

void	swap(int *array, int a, int b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

void	sort_array(int *array)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 8)
		{
			if (array[j] > array[j + 1])
				swap(array, j, j + 1);
			j++;
		}
		i++;
	}
}

void	solve_array(int *array)
{
	int i;
	int j;
	int sum;

	i = 0;
	sum = 0;
	while (i < 9)
	{
		sum += array[i];
		i++;
	}
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (i != j)
			{
				sum = sum - (array[i] + array[j]);
				if (sum == 100)
				{
					array[i] = 999;
					array[j] = 999;
					sort_array(array);
					return ;
				}
				sum = sum + (array[i] + array[j]);
			}
			j++;
		}
		i++;
	}
}

int main(void)
{
	int array[9];
	int i;

	get_array(array);
	sort_array(array);
	solve_array(array);
	print_array(array);
	return (0);
}

//메모리를잡고 선언한 배열은 주소값을 넘겨주지 않아도 그 값을 변경할수가 있구나
//따라서 주소값 &를 굳이 안붙여도, 또 넘겨받은 함수내에서 *로 역참조를 하지 않아도 값을 변경할 수 있다.
//오히려 &로 주소값을 넘겨주려하면 오류가 발생한다.
//동적할당 할때의 쓰임과 다르다는것 기억할것.
//뭔가 배열선언시 크기까지 같이 주면 객체가 생기고 함수에 그 객체 자체를 넘겨주는 느낌?
