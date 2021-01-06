#include<stdio.h>
int max=0;
void join(int *a, int t, int sum)
{
    int tmp[4] = {0};
    int i, j;
    int s;
    if(t == 1)
    {
        if(max < sum) max = sum;
        return;
    }
    for(i = 0; i < t - 1; i ++)
    {
        for(j = 0; j < i; j ++)
            tmp[j] = a[j];
        tmp[j] = a[j]+a[j+1];
        s = sum + tmp[j];
        for(j++;j<t-1; j ++)
            tmp[j] = a[j+1];
        join(tmp, t-1, s);
    }
}

int main()
{
    int a[4] = {4,4,5,9};
    int sum = 0;
    join(a, 4, sum);
    printf("result = %d\n", max);
    return 0;
}