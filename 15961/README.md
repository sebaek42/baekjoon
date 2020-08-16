## 문제

회전 초밥 음식점에는 회전하는 벨트 위에 여러 가지 종류의 초밥이 접시에 담겨 놓여 있고, 손님은 이 중에서 자기가 좋아하는 초밥을 골라서 먹는다. 초밥의 종류를 번호로 표현할 때, 다음 그림은 회전 초밥 음식점의 벨트 상태의 예를 보여주고 있다. 벨트 위에는 같은 종류의 초밥이 둘 이상 있을 수 있다.

[https://upload.acmicpc.net/f29f0bd9-6114-4543-aa72-797208dc9cdd/-/preview/](https://upload.acmicpc.net/f29f0bd9-6114-4543-aa72-797208dc9cdd/-/preview/)

새로 문을 연 회전 초밥 음식점이 불경기로 영업이 어려워서, 다음과 같이 두 가지 행사를 통해서 매상을 올리고자 한다.

1. 원래 회전 초밥은 손님이 마음대로 초밥을 고르고, 먹은 초밥만큼 식대를 계산하지만, 벨트의 임의의 한 위치부터 k개의 접시를 연속해서 먹을 경우 할인된 정액 가격으로 제공한다.
2. 각 고객에게 초밥의 종류 하나가 쓰인 쿠폰을 발행하고, 1번 행사에 참가할 경우 이 쿠폰에 적혀진 종류의 초밥 하나를 추가로 무료로 제공한다. 만약 이 번호에 적혀진 초밥이 현재 벨트 위에 없을 경우, 요리사가 새로 만들어 손님에게 제공한다.

위 할인 행사에 참여하여 가능한 한 다양한 종류의 초밥을 먹으려고 한다. 위 그림의 예를 가지고 생각해보자. k=4이고, 30번 초밥을 쿠폰으로 받았다고 가정하자. 쿠폰을 고려하지 않으면 4가지 다른 초밥을 먹을 수 있는 경우는 (9, 7, 30, 2), (30, 2, 7, 9), (2, 7, 9, 25) 세 가지 경우가 있는데, 30번 초밥을 추가로 쿠폰으로 먹을 수 있으므로 (2, 7, 9, 25)를 고르면 5가지 종류의 초밥을 먹을 수 있다.

회전 초밥 음식점의 벨트 상태, 메뉴에 있는 초밥의 가짓수, 연속해서 먹는 접시의 개수, 쿠폰 번호가 주어졌을 때, 손님이 먹을 수 있는 초밥 가짓수의 최댓값을 구하는 프로그램을 작성하시오.

## 입력

첫 번째 줄에는 회전 초밥 벨트에 놓인 접시의 수 N, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c가 각각 하나의 빈 칸을 사이에 두고 주어진다. 단, 2 ≤ N ≤ 3,000,000, 2 ≤ d ≤ 3,000, 2 ≤ k ≤ 3,000 (k ≤ N), 1 ≤ c ≤ d이다. 두 번째 줄부터 N개의 줄에는 벨트의 한 위치부터 시작하여 회전 방향을 따라갈 때 초밥의 종류를 나타내는 1 이상 d 이하의 정수가 각 줄마다 하나씩 주어진다.

## 출력

주어진 회전 초밥 벨트에서 먹을 수 있는 초밥의 가짓수의 최댓값을 하나의 정수로 출력한다.

## 예제 입력 1

```
8 30 4 30
7
9
7
30
2
7
9
25

```

## 예제 출력 1

```
5

```

## 예제 입력 2

```
8 50 4 7
2
7
9
25
7
9
7
30

```

## 예제 출력 2

```
4
```

## 참고 링크: [https://jaimemin.tistory.com/767](https://jaimemin.tistory.com/767)

# 접근방법

- 1 ~ K개의 스시를 '덱'(deque)에 집어 넣고 종류를 센다
- N - 1번 반복문을 돌리면서 맨앞의 스시를 빼고 다음 스시를 덱에 넣는다
- 뺀 스시의 종류가 덱에 더이상 없을경우 cnt뺀다
- 넣은 스시종류가 기존 덱에 존재하지 않을경우 cnt 더한다
- 덱에 쿠폰으로 제공되는 스시의 종류가 없다면 cnt하나 더한다
- 구한 값중 최대를 출력
- 회전 초밥집이기 때문에 스시 인덱스를 (i + K) % N으로 해야한다

# 코드

```cpp
// 1 ~ K개의 스시를 덱에 집어넣고 종류를 셈
// N -1 번 반복문을 돌리면서 맨앞에 있는 스시를 빼고 다음 스시를 덱에 넣어
// 뺀 스시의 종류가 덱에 더이상 없을경우 cnt를 빼줘
// 집어 넣은 스시의 종류가 기존덱에 존재하지 않을경우  cnt더해
// 덱에 쿠폰으로 제공되는 스시의 종류가 없을 경우 cnt하나 더해
// 구한 값중 최대를 출력

//회전 초밥집이기 때문에 스시 인덱스를 (i + K) % N으로 해줘야함

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std; //이걸 쓰면 헤더 include 할때 뒤에 .h안붙여도댐

const int MAX = 3000000;
deque<int> dq; // deque<데이터타입> 변수명; -> push_front() pop_front(), push_back(), pop_back(), 중간에 원소 삽입 삭제도 가능
int N, D, K, C;
int result;
int sushi[MAX];
int kind[3000 + 1] = {0};

int main()
{
	ios_base::sync_with_stdio(false); // cpp의 iostream을 c의 stdio와 동기화해주는 작업을 하는애인데 1(true)을 주게되면 iostream과 stdio 버퍼를 모두 사용하기 때문에 딜레이가 발생하게 된다. 이 동기화 부분을 0(false)를 줘서 끊어주면 c++만의 독립적인 버퍼를 생성하게되고 C의 버퍼들과는 병행하여 사용할 수 없게 된다 대신 속도가 높아진다
	cin.tie(NULL); // cout, cin이 원랜 tie되어있다. 만약 cout << "hi" cin >> name 순서라면 hi가 먼저 출력되고 name을 입력하게됨. 그러나 untie할 경우 cout으로부터 cin을 untie해주기 때문에 먼저 입력을 받게된다. cout은 버퍼가 가득찼을경우에만 flushed되고 출력되기 때문에 hi는 출력되지 않는다. 따라서 cin을 cout에서 untie하고 싶다면 cin으로 입력하기 전에 cout으로 출력을 할때마다 지속적으로 flush해줘야한다.
	cin >> N >> D >> K >> C;
	for(int i = 0; i < N; i++)
		cin >> sushi[i];
	int cnt = 0;
	for (int i = 0; i < K; i++)
	{
		// 맨뒤 스시 추가
		dq.push_back(sushi[i]);
		// 일단 증가시키되 0이였으면 카운트도 1더해줌
		if (!kind[sushi[i]]++)
		{
			cnt++;
		}
		result = max(result, cnt);
	}
	for(int i = 0; i < N-1; i++)
	{
		// 맨앞 스시 빼기
		dq.pop_front();
		// 뺀 스시의 종류와 같은 스시가 덱에 없다면
		if (!(--kind[sushi[i]]))
		// 카운트를 하나 뺌
			cnt--;
		// 다음 스시 추가. 원형이니까 인덱스 조정
		dq.push_back(sushi[(i + K) % N]);
		// 새로운 종류면 cnt더해줌
		if (!kind[sushi[(i + K) % N]]++)
			cnt++;
		// 쿠폰스시가 없는 상태라면
		if (!kind[C])
			result = max(result, cnt + 1);
		// 쿠폰스시가 있는 상태라면
		else
			result = max(result, cnt);
	}
	cout << result << "\n";
	return 0;
}
```