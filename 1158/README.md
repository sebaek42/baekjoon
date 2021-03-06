## 문제

<p>요세푸스 문제는 다음과 같다.<p>

<p>1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.<p>

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 5,000)

## 출력

예제와 같이 요세푸스 순열을 출력한다.

## 예제 입력 1

```
7 3

```

## 예제 출력 1

```
<3, 6, 2, 7, 5, 1, 4>
```

# 접근 방법

<p>처음엔 문자열을 두개 선언하고 문자열 하나는 1부터 N까지 숫자를 담고 반복문을 돌면서 한 자리씩 다른 문자열에 넘겨주면서 한칸씩 줄어드는 형태로 문제를 풀어보려했다. 그러나 코드가 너무 복잡해져서 짜면서도 헷갈리는 코드가 되어버렸다. 결국 다른방법을 고안해야했다<p>

<p>수학적인 접근방법을 할 수 있지 않을까 생각해봤다. N명이 있고 K번째 사람이 빠지는거니까 일단 N명의 번호를 담을 배열을 하나 선언해두고, 빠진 자리는 0으로 채워주면, 다음에 빠질 사람의 인덱스를 구하는게 좀 더 쉬워질것 같았다. K번째 사람이 빠지면 빠진자리를 0으로 채우고, 그 다음 K번째 사람을 구하되, 만약 다음 자리가 0이면 세지 않은셈치고 넘어가면 되지 않을까. 또, 한자리씩 검사하려고 인덱스를 하나씩 증가하는데 그 때 전체 범위를 넘을수 있으니까 배열값을 들여다 보기전에 나머지 연산만 한번 해주면 되지 않을까. 그래서 다음의 코드가 탄생했다.<p>

```
out = K;
while (i < N)  // 반복조건은 중요치않다. 어짜피 break로 빠져나올거임.
	{
		if (i == N - 1) //마지막 요소인 경우 출력조건 다르게해주기 위해
		{
			printf("%d>", circle[out - 1]);
			break ;
		}
		else
			printf("%d, ", circle[out - 1]); //일단 out번째는 빼주되, 인덱스에선 -1해줘야하니까.
		circle[out - 1] = 0; //빠진 자리 0으로 채워주고
		j = 0;
		tmp = out + 1;
		// 이제 사람이 있나 볼건데, 있을경우만 셌다고 쳐서 쭉 넘겨봤을때, K번만큼 뒤에있는 사람이 있는 인덱스를 구해줌
		while (j < K)
		{
			if (tmp > N) //넣어보기전에 크기 체크
				tmp = tmp % N;
			if (circle[tmp - 1] != 0) //0이 아닌경우만 셋다고 침
				j++;
			tmp++; //인덱스는 계속 돌게끔. 단 원처럼 작동해야하기때문에 위에서 크기는 조정해줄거임.
		}
		out = tmp - 1;
		i++;
	}
```

# 어려웠던점

이번 문제같은 경우, 문자열을 새롭게 만들고 조정하고 인덱스값 구하고 하는걸 똑바로 생각하기 힘들었다. 게다가 매번 기존 문자열에서 특정 인덱스값을 뺀 새로운 문자열을 만들어야 한다면 시간도 오래 걸릴것이 분명했다. 그래서 기존의 생각을 좀 버리고 다른 아이디어를 고안해내야 했는데, 하려면 할수 있지만 시간이 너무 오래걸린것이 문제다. 어떻게든 빠르게 생각을 해야 실전에 활약할 수 있을텐데, 연습을 통해 사고하는 능력을 길러야겠다.
