#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	int x;
	int y;

	x = *(int *)a;
	y = *(int *)b;
	if (x > y)
		return 1;
	else if (x < y)
		return -1;
	else
		return 0;
}

int main()
{
	int N, C;
	int home[200000] = {0};
	int i;

	scanf("%d %d", &N, &C);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &home[i]);
	}
	qsort(home, N, sizeof(int), compare);
	int left = 1; // 가능한 최소거리
	int right = home[N - 1] - home[0]; // 가능한 최대거리
	int distance = 0;
	int answer = 0;

	while (left <= right) {
		int mid = (left + right) / 2; // 기준거리
		int start = home[0];
		int cnt = 1;

		for (i = 1; i < N; i++) { //간격을 기준으로 공유기 설치
			distance = home[i] - start;
			if (mid <= distance) {
				cnt++; // 공유기 설치
				start = home[i];
			}
		}
		if (cnt >= C) { // 설치한 공유기가 설치할 공유기보다 많거나 같다면,
			answer = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	printf("%d", answer);
}
