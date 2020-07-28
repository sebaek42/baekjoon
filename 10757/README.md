# 문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

# 입력
첫째 줄에 A와 B가 주어진다. (0 < A,B < 1010000)

# 출력
첫째 줄에 A+B를 출력한다.

# 예제 입력 1 
9223372036854775807 9223372036854775808

# 예제 출력 1 
18446744073709551615

# 접근방법
입력을 정수로받으면 오버플로우가 발생할수있다. 따라서 문자열로 입력을 받아 더하기처리를 해야한다.
단, 더하는 순서와 배열의 인덱스 접근이 서로 상충되니 인덱스에 배열을 맞춰주기위해 입력받은 문자열 요소를 역순으로 뒤집어준다. 그 뒤 각 요소를 더해주되 자리올림이 발생했는지 안했는지에 따라 분기해서 처리해준다.
# 느낀점
- 문자 하나를 정수로 바꾸는 매크로 함수를 제작해서 사용했는데 요긴하게 사용했다. 또, string라이러리도 사용하면서 코딩시간을 단축시킬수있었다.
- 접근방법이 중요한 문제인것같다. 문자열끼리 바로 더해주려고한다면 예외처리해야할 요소가 늘어나기때문에 최대한 반복문안에서 심플함을 유지할 수 있도록 배열의 요소를 조정해주는게 좋은것 같다.
```
#include <stdio.h>
#include <string.h>
#define atoi(X) (X==0?0:X-'0')

void	reverse(char *array, int len)
{
	char tmp;
	int i;

	i = 0;
	while (i < len / 2)
	{
		tmp = array[i];
		array[i] = array[len - 1 -i];
		array[len - 1 - i] = tmp;
		i++;
	}
	return ;
}

char *add(char *A, char *B, char *S)
{
	int len;
	int carry;
	int i;

	if (strlen(A) > strlen(B))
		len = strlen(A);
	else
		len = strlen(B);
	reverse(A, strlen(A));
	reverse(B, strlen(B));
	i = 0;
	carry = 0;
	while (i <= len)
	{
		S[i] = atoi(A[i]) + atoi(B[i]) + carry;
		if (S[i] >= 10)
		{
			S[i] = S[i] - 10 + '0';
			carry = 1;
		}
		else
		{
			S[i] = S[i] + '0';
			carry = 0;
		}
		i++;
	}
	if (S[len] == '0')
		S[len] = 0;
	reverse(S, strlen(S));
	return S;
}

int main()
{
	char A[100000];
	char B[100000];
	char S[100000];
	scanf("%s %s", A, B);
	add(A, B, S);
	printf("%s", S);
	return (0);
}
```

