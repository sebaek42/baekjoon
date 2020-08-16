## 문제

공화국에 있는 유스타운 시에서는 길을 사이에 두고 전봇대가 아래와 같이 두 줄로 늘어서 있다. 그리고 길 왼편과 길 오른편의 전봇대는 하나의 전선으로 연결되어 있다. 어떤 전봇대도 두 개 이상의 다른 전봇대와 연결되어 있지는 않다.

![https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/upload/201004/picpicpicpicpicpicpicp.JPG](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/upload/201004/picpicpicpicpicpicpicp.JPG)

문제는 이 두 전봇대 사이에 있는 전깃줄이 매우 꼬여 있다는 점이다. 꼬여있는 전깃줄은 화재를 유발할 가능성이 있기 때문에 유스타운 시의 시장 임한수는 전격적으로 이 문제를 해결하기로 했다.

임한수는 꼬여 있는 전깃줄 중 몇 개를 적절히 잘라 내어 이 문제를 해결하기로 했다. 하지만 이미 설치해 놓은 전선이 아깝기 때문에 잘라내는 전선을 최소로 하여 꼬여 있는 전선이 하나도 없게 만들려고 한다.

유스타운 시의 시장 임한수를 도와 잘라내야 할 전선의 최소 개수를 구하는 프로그램을 작성하시오.

## 입력

첫 줄에 전봇대의 개수 N(1 ≤ N ≤ 100,000)이 주어지고, 이어서 N보다 작거나 같은 자연수가 N개 주어진다. i번째 줄에 입력되는 자연수는 길 왼쪽에 i번째 전봇대와 연결된 길 오른편의 전봇대가 몇 번 전봇대인지를 나타낸다.

## 출력

전선이 꼬이지 않으려면 최소 몇 개의 전선을 잘라내야 하는 지를 첫째 줄에 출력한다.

## 예제 입력 1

```
4
2 3 4 1

```

## 예제 출력 1

```
1
```

# 접근방법

입력받은 배열의 요소를 하나씩 보면서 이전값보다 작은값이 들어오면 이제까지 본 배열요소중 적합한 위치로 보내주고 카운트를 센다

끝까지 다 비교해서 바꿔줬을때 센 카운트 갯수만큼이 자른 전선의 수

# 코드

```cpp
#include <stdio.h>
#include <stdlib.h>

int lower_bound(int left, int right, int value, int **b)  //
{
	while (left <= right) // 이진 탐색으로 적절한 위치를 찾아서 위치값 반환
	{
		int mid = (left + right) / 2;
		if ((*b)[mid] >= value)
			right = mid - 1;
		else
		{
			left = mid + 1;
		}
	}
	return left;
}

int main()
{
	int n;
	scanf("%d", &n);
	int *a;
	int *b;
	a = malloc(sizeof(int) * n); // 입력받을 배열
	b = malloc(sizeof(int) * n); //
	int i;
	int count;

	count = 0;
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int size = 1;
	b[0] = a[0];
	for (i = 1; i < n; i++) // 루프 한번으로 해결
	{
		if (b[size - 1] <= a[i]) // 이전게 지금값보다 작은 값이면 그대로 배열b에 복사
		{
			b[size] = a[i];
			size++;
		}
		else // 그렇지않고 지금 보는 값이 이전값보다 작은 값이라면 지금 값을 배열 b의 적절한 위치에 넣어준다
		{
			b[lower_bound(0, size - 1, a[i], &b)] = a[i];
			count++;
		}
	}
	printf("%d", count);
	return 0;
}
```
