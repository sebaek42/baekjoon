# 문제
<p>상근이는 나무 M미터가 필요하다. 근처에 나무를 구입할 곳이 모두 망해버렸기 때문에, 정부에 벌목 허가를 요청했다. 정부는 상근이네 집 근처의 나무 한 줄에 대한 벌목 허가를 내주었고, 상근이는 새로 구입한 목재절단기를 이용해서 나무를 구할것이다.</p>

<p>목재절단기는 다음과 같이 동작한다. 먼저, 상근이는 절단기에 높이 H를 지정해야 한다. 높이를 지정하면 톱날이 땅으로부터 H미터 위로 올라간다. 그 다음, 한 줄에 연속해있는 나무를 모두 절단해버린다. 따라서, 높이가 H보다 큰 나무는 H 위의 부분이 잘릴 것이고, 낮은 나무는 잘리지 않을 것이다. 예를 들어, 한 줄에 연속해있는 나무의 높이가 20, 15, 10, 17이라고 하자. 상근이가 높이를 15로 지정했다면, 나무를 자른 뒤의 높이는 15, 15, 10, 15가 될 것이고, 상근이는 길이가 5인 나무와 2인 나무를 들고 집에 갈 것이다. (총 7미터를 집에 들고 간다)</p>

<p>상근이는 환경에 매우 관심이 많기 때문에, 나무를 필요한 만큼만 집으로 가져가려고 한다. 이때, 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.</p>

# 입력
<p>첫째 줄에 나무의 수 N과 상근이가 집으로 가져가려고 하는 나무의 길이 M이 주어진다. (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)</p>

<p>둘째 줄에는 나무의 높이가 주어진다. 나무의 높이의 합은 항상 M을 넘기 때문에, 상근이는 집에 필요한 나무를 항상 가져갈 수 있다. 높이는 1,000,000,000보다 작거나 같은 양의 정수 또는 0이다.</p>

# 출력
적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.

# 예제 입력 1 
<br>4 7
<br>20 15 10 17
# 예제 출력 1 
<br>15

# 접근방법
첫번째 접근법
- 길이가 가장 긴 나무의 길이부터 자를 높이를 하나씩 낮춰가면 되지않을까?
- 하나씩 하나씩 낮춰가면서 그 높이일때 얻을수있는 나무의 길이가 요구량에 충족하는지를 봤다
- 문제를 풀긴했지만 시간초과가 발생했다 

두번째 접근법
- 길이가 가장 긴 나무부터 내려가기시작해서 느렸던게 아닐까?
- 속도를 높이려면 나무들의 평균길이부터 시작해서 하나씩 올리던가 내려보면 어떨까?
- 이방법 역시 시간초과

세번째 접근법
- 인터넷 찬스를 활용하여 이분탐색이라는 알고리즘을 발굴했다
- 이분 탐색은 원래 정렬된 배열에 최소(left), 최대(right) 인덱스를 설정한 뒤 그 중간의 인덱스값(mid = (left + right) / 2)을 목표로하는 값과 비교해서 낮으면 최대 인덱스를 중간 인덱스-1로(right = mid - 1), 높으면 최소 인덱스 값을 중간 인덱스+1로(left = mid + 1) 설정한뒤 최소 인덱스가 최대 인덱스와 같거나 같을때까지 반복시키는 알고리즘이다.
- 정렬된 배열이 기본적으로 적용가능한 대상이지만, 이 문제의 경우 높이가 올라갈수록 결과값이 줄어드는 내림차순 정렬의 형태를 보이므로 충분히 적용가능하다

```
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    int max;
    int i;
    int *tree;
    long long left;
    long long right;
    long long mid;
    int result;
    long long sum;

    scanf("%d %d", &N, &M);
    max = 0;
    i = 0;
    if (!(tree = malloc(sizeof(int) * N)))
        return (0);
    while (i < N)
    {
        scanf("%d", &tree[i]);
        if (max < tree[i])
            max = tree[i];
        i++;
    }
    left = 1;
    right = max;
    result = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        sum = 0;
        i = 0;
        while (i < N)
        {
            if (tree[i] > mid)
                sum += tree[i] - mid;
            i++;
        }
        if (M > sum)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
            result = mid;
        }
    }
    printf("%d\n", result);
}
```
# 어려웠던 점
- 시간초과를 해결하는게 어려웠다
- 자료형의 크기를 int로 주면 틀리게 되는데, sum같은 경우 값을 더하다보면 int의 최대값이 담길수도 있기 때문에 8바이트인 long long으로 선언해줘야한다. 알고리즘은 맞았는데 틀렸습니다!가 뜨는건 이게 원인이다.
