## 문제

예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

## 입력

첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

## 출력

첫째 줄부터 차례대로 별을 출력한다.

## 예제 입력 1

```
1

```

## 예제 출력 1

```
*

```

## 예제 입력 2

```
2

```

## 예제 출력 2

```
*****
*   *
* * *
*   *
*****

```

## 예제 입력 3

```
3

```

## 예제 출력 3

```
*********
*       *
* ***** *
* *   * *
* * * * *
* *   * *
* ***** *
*       *
*********

```

## 예제 입력 4

```
4

```

## 예제 출력 4

```
*************
*           *
* ********* *
* *       * *
* * ***** * *
* * *   * * *
* * * * * * *
* * *   * * *
* * ***** * *
* *       * *
* ********* *
*           *
*************
```

## 접근방법

입력값 N을 토대로 규칙을 파악해보았다

길이 4(N-1)+1의 네모가 찍히는데 그 안에 길이 1의 상자가 찍힐때까지 반복되는 모양이다.

처음엔 최대 길이정보와 현재 좌표 만으로 규칙에 따라 별을 찍어갈수 있도록 만들어보려 고민했다. 고민이 너무 길어지고 규칙을 생각해내기 너무 어려워서 재귀를 생각해봤다. 

재귀를 하려면 인덱스로 접근해서 재귀로 값을 채워줄 이차원배열이 필요했다. 재귀는 다음과 같다.

- 최초로 0,0 포인트를 잡고 길이만큼 위, 아래, 가로, 세로를 별로 채워준다.
- 탈출 조건은 N이 1일때 별을 하나 찍고 리턴
- 재귀시 N-1을 인자로 넘겨줘서 사이즈가 하나씩 줄도록
- 시작할 좌표도 +2씩 해줌으로 그림의 규칙을 지킬수있도록

## 코드

```jsx
#include <stdio.h>
#include <stdlib.h>

void	init_stars(char ***stars, int N)
{
	int len;
	int i;
	int j;

	len = 4*(N - 1) + 1;
	if (!((*stars) = malloc(sizeof(char *) * len)))
		return ;
	i = 0;
	while (i < len)
	{
		if (!((*stars)[i] = malloc(sizeof(char) * len)))
			return ;
		j = 0;
		while (j < len)
		{
			(*stars)[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	fill_stars(char ***stars, int N, int col, int row)
{
	int len;
	int i;
	int j;

	len = 4 * (N - 1) + 1;
	if (N == 1)
	{
		(*stars)[row][col] = '*';
		return ;
	}
	j = col;
	while (j < col + len)
	{
		(*stars)[row][j] = '*';
		(*stars)[row + len - 1][j] = '*';
		j++;
	}
	i = row;
	while (i < row + len)
	{
		(*stars)[i][col] = '*';
		(*stars)[i][col + len - 1] = '*';
		i++;
	}
	fill_stars(stars, N - 1, col + 2, row + 2);
	return ;
}

void	print_stars(char **stars, int N)
{
	int len;
	int i;
	int j;

	len = 4 *(N - 1) + 1;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			printf("%c", stars[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int main(void)
{
	int N;
	char **stars;

	scanf("%d", &N);
	init_stars(&stars, N);
	fill_stars(&stars, N, 0, 0);
	print_stars(stars, N);
	//free_stars(stars);
}
```
