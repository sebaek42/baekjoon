#include <stdio.h>
#include <stdlib.h>

void init_list(int ***list, int C)
{
    int i;
    int j;
    int num;

    i = 0;
    if (!((*list) = malloc(sizeof(int *) * C)))
        return ;
    while (i < C)
    {
        j = 0;
        scanf("%d", &num);
        if (!((*list)[i] = malloc(sizeof(int) * (num + 1))))
            return ;
        (*list)[i][j++] = num;
        while (j < num + 1)
        {
            scanf("%d", &(*list)[i][j]);
            j++;
        }
        i++;
    }
}

void set_result(int **list, float **result, int C)
{
    int i;
    int j;
    float mid;
    int cnt;

    i = 0;
    if (!((*result) = malloc(sizeof(float) * C)))
        return ;
    while (i < C)
    {
        j = 1;
        mid = 0.0;
        while (j < list[i][0] + 1)
        {
            mid += list[i][j];
            j++; 
        }
        mid = mid / list[i][0];
        j = 1;
        cnt = 0;
        while (j < list[i][0] + 1)
        {
            if ((float)list[i][j] > mid)
            {
                cnt++;
            }
            j++;
        }
        (*result)[i] = ((float)cnt / list[i][0]) * 100;
        i++;
    }
}

void print_result(float *result, int C)
{
    int i = 0;
    while (i < C)
    {
        printf("%.3f%%", result[i]);
        i++;
        if (i < C)
            printf("\n");
    }
}

int main(void)
{
    int C;
    int **list;
    float *result;

    scanf("%d", &C);
    init_list(&list, C);
    set_result(list, &result, C);
    print_result(result, C);
    //free_list(list);
    //free(result);
    return (0);
}