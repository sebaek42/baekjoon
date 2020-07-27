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
