## 문제

빙고 게임은 다음과 같은 방식으로 이루어진다.

먼저 아래와 같이 25개의 칸으로 이루어진 빙고판에 1부터 25까지 자연수를 한 칸에 하나씩 쓴다

![https://www.acmicpc.net/upload/images/WKbsKmfyQqDPPVWaQP5S63VZvs.gif](https://www.acmicpc.net/upload/images/WKbsKmfyQqDPPVWaQP5S63VZvs.gif)

다음은 사회자가 부르는 수를 차례로 지워나간다. 예를 들어 5, 10, 7이 불렸다면 이 세 수를 지운 뒤 빙고판의 모습은 다음과 같다.

![https://www.acmicpc.net/upload/images/JJQjutdbf6R7UPKydGbcDnCToNy7TT.gif](https://www.acmicpc.net/upload/images/JJQjutdbf6R7UPKydGbcDnCToNy7TT.gif)

차례로 수를 지워가다가 같은 가로줄, 세로줄 또는 대각선 위에 있는 5개의 모든 수가 지워지는 경우 그 줄에 선을 긋는다.

![https://www.acmicpc.net/upload/images/zYg1NjhdAa5pP5iL3UhnESclHwN9BZde.gif](https://www.acmicpc.net/upload/images/zYg1NjhdAa5pP5iL3UhnESclHwN9BZde.gif)

이러한 선이 세 개 이상 그어지는 순간 "빙고"라고 외치는데, 가장 먼저 외치는 사람이 게임의 승자가 된다.

![https://www.acmicpc.net/upload/images/E3GJSMvVy14jeFZxjoNYs8aYW4ai.gif](https://www.acmicpc.net/upload/images/E3GJSMvVy14jeFZxjoNYs8aYW4ai.gif)

철수는 친구들과 빙고 게임을 하고 있다. 철수가 빙고판에 쓴 수들과 사회자가 부르는 수의 순서가 주어질 때, 사회자가 몇 번째 수를 부른 후 철수가 "빙고"를 외치게 되는지를 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄부터 다섯째 줄까지 빙고판에 쓰여진 수가 가장 위 가로줄부터 차례대로 한 줄에 다섯 개씩 빈 칸을 사이에 두고 주어진다. 여섯째 줄부터 열째 줄까지 사회자가 부르는 수가 차례대로 한 줄에 다섯 개씩 빈 칸을 사이에 두고 주어진다. 빙고판에 쓰여진 수와 사회자가 부르는 수는 각각 1부터 25까지의 수가 한 번씩 사용된다.

## 출력

첫째 줄에 사회자가 몇 번째 수를 부른 후 철수가 "빙고"를 외치게 되는지 출력한다.

## 예제 입력 1

```
11 12 2 24 10
16 1 13 3 25
6 20 5 21 17
19 4 8 14 9
22 15 7 23 18
5 10 7 16 2
4 22 8 17 13
3 18 1 6 25
12 19 23 14 21
11 24 9 20 15
```

## 예제 출력 1

```
15
```

# 접근방법

빙고판은 2차원배열에 저장하고 심판이 부르는 숫자는 반복문속 인덱스 증가로 간편하게 불러올수있도록 1차원 배열에 저장한다

숫자하나를 체크할때마다 카운터를 증가시키고 빙고여부를 가리는 함수를 돌도록 해서 빙고일경우 루프를 중단하고 카운트를 출력하도록 한다

# 어려웠던점

시간을 단축시키기위해 최대한 루프를 줄이고자 노력했다. 빙고여부를 체크하는 함수가 만만찮았는데 , 가로 세로 대각선 세종류의 빙고여부를 최소한의 루프로 가려내야했기 때문이다

가로 세로의 경우 어쨌든 루프 한번이면 '한 줄'에 대한 빙고 여부를 가릴수 있기 때문에 카운터 초기화 지점을 이중반복의 두번째 반복문 이전으로 잡으면 된다. 그러나 대각선은 그렇지 않다. 대각선의 경우 '여러 줄'에 대한 검사를 바탕으로 이뤄지기 때문에 이중 반복문의 첫번째 반복문 이전에 초기화 포인트를 잡아야했다

# 배운 점

반복문 속 카운터의 생존주기에 대해 생각해볼 수 있었다

빙고같은 경우 5칸으로 정해져있기 때문에 동적할당을 하지 않고 메인문안에 배열크기를 선언해서 해결했다

배열크기를 선언한뒤 이걸 함수에 넘겨줄때가 항상 고민이었는데 구글링결과

1차원 배열일때

반환타입  함수이름(자료형 배열이름[])

2차원 배열일때

반환타입 함수이름(자료형 배열이름[][가로크기])

# 코드

```swift
#include <stdio.h>

void	check(int board[][5], int tmp)
{
	int i;
	int j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			if (board[i][j] == tmp)
			{
				board[i][j] = 0;
			}
			j++;
		}
		i++;
	}
}

int		bingo(int board[][5])
{
	int i = 0;
	int j = 0;
	int bingo = 0;
	int rowcount;
	int colcount;
	int ldiagonal;
	int udiagonal;

	ldiagonal = 0;
	udiagonal = 0;
	while (i < 5)
	{
		j = 0;
		rowcount = 0;
		colcount = 0;
		while (j < 5)
		{
			if (board[i][j] == 0)
			{
				rowcount++;
			}
			if (board[j][i] == 0)
			{
				colcount++;
			}
			if ((i == j) && board[i][j] == 0 )
			{
				ldiagonal++;
			}
			if ((i + j == 4) && board[i][j] == 0)
			{
				udiagonal++;
			}
			j++;
		}
		if (rowcount == 5)
		{
			bingo++;
		}
		if (colcount == 5)
		{
			bingo++;
		}
		if (ldiagonal == 5)
		{
			bingo++;
		}
		if (udiagonal == 5)
		{
			bingo++;
		}
		if (bingo == 3)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int main()
{
	int board[5][5];
	int tmp[25];
	int count;
	int i;
	int j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			scanf("%d", &board[i][j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 25)
	{
		scanf("%d", &tmp[i]);
		i++;
	}
	count = 0;
	while (count < 25)
	{
		check(board, tmp[count]);
		count++;
		if (bingo(board))
			break;
	}
	printf("%d", count);
}
```
