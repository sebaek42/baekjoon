## 문제

현진 치킨에서 판매하는 치킨은 양념 치킨, 후라이드 치킨, 반반 치킨으로 총 세 종류이다. 반반 치킨은 절반은 양념 치킨, 절반은 후라이드 치킨으로 이루어져있다. 양념 치킨 한 마리의 가격은 A원, 후라이드 치킨 한 마리의 가격은 B원, 반반 치킨 한 마리의 가격은 C원이다.

상도는 오늘 파티를 위해 양념 치킨 최소 X마리, 후라이드 치킨 최소 Y마리를 구매하려고 한다. 반반 치킨을 두 마리 구입해 양념 치킨 하나와 후라이드 치킨 하나를 만드는 방법도 가능하다. 상도가 치킨을 구매하는 금액의 최솟값을 구해보자.

## 입력

첫째 줄에 다섯 정수 A, B, C, X, Y가 주어진다.

## 출력

양념 치킨 최소 X마리, 후라이드 치킨 최소 Y마리를 구매하는 비용의 최솟값을 출력한다.

## 제한

- 1 ≤ A, B, C ≤ 5,000
- 1 ≤ X, Y ≤ 100,000

## 예제 입력 1

```
1500 2000 1600 3 2

```

## 예제 출력 1

```
7900

```

반반 치킨 4마리를 구매해서, 양념 치킨 2마리와 후라이드 치킨 2마리를 만들고, 양념 치킨 1마리를 구매하는 것이 최소이다.

## 예제 입력 2

```
1500 2000 1900 3 2

```

## 예제 출력 2

```
8500

```

## 예제 입력 3

```
1500 2000 500 90000 100000

```

## 예제 출력 3

```
100000000
```

# 접근방법

반반으로 두개 산 가격이 하나씩 산 가격보다 싸다면 반반을 활용할 여지가 있는것으로 판단한다

개수 X Y중 더 작은 수만큼은 반반으로 사도록하고(더 작은 수 * 2 를 해야 제대로 개수 채워짐) 남은 개수만큼 한마리 가격에 따라서 곱해서 총 가격을 구한다.

단, 그렇게 구한 총 가격보다 X Y중 큰수를 기준으로 반반을 산 가격이 더 저렴한지 체크해본다

# 코드

```swift
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
```
