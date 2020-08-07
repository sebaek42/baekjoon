## 문제

N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

## 입력

첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.

## 출력

첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

## 예제 입력 1

```
10
5
2
3
1
4
2
3
5
1
7

```

## 예제 출력 1

```
1
1
2
2
3
3
4
5
5
7
```

# 접근방법

1. 퀵소트
2. 카운터정렬

처음엔 stdlib.h에 구현되어있는 퀵소트를 활용했다

그러나 메모리초과로 통과하지 못했다

빠를진 몰라도 메모리를 수의 개수만큼 잡아먹다보니 1000만개의 사이즈를 할당할때 메모리가 부족해진것 같다

결국 카운터 정렬이라는 알고리즘을 찾을수 있었다

카운터 정렬이란?

입력받는 숫자의 범위만큼 배열을 선언하고 배열의 인덱스 값이 곧 입력받은 숫자인 것으로 생각해서 숫자가 들어오면 해당 인덱스의 값을 1증가시킨뒤, 카운트된 개수만큼 차례대로 출력해주는 방식이다

# 퀵소트 코드

 

```c
#include <stdio.h>
#include <stdlib.h>

void	init(int **list, int N)
{
	int i;

	i = 0;
	while (i < N)
	{
		scanf("%d", &(*list)[i]);
		i++;
	}
}

int		compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;
	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;
	return 0;
}

void	print_list(int *list, int N)
{
	int i = 0;

	while (i < N)
	{
		printf("%d", list[i]);
		i++;
		if (i < N)
			printf("\n");
	}
}

int main()
{
	int N;
	int *list;

	scanf("%d", &N);
	if (!(list = malloc(sizeof(int) * N)))
		return (-1);
	init(&list, N);
	qsort(list, N, sizeof(int), compare);
	print_list(list, N);
	free(list);
}
```

# 카운터 코드

```c
#include <stdio.h>

int main()
{
	int N;
	int num;
	int count[10001] = {0, };
	int i;
	int j;

	scanf("%d", &N);
	i = 0;
	while (i < N)
	{
		scanf("%d", &num);
		count[num]++;
		i++;
	}
	i = 0;
	while (i < 10001)
	{
		if (count[i] != 0)
		{
			j = 0;
			while (j < count[i])
			{
				printf("%d\n", i);
				j++;
			}
		}
		i++;
	}
	return 0;
}
```
