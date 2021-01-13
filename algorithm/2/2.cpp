#include<iostream>
using namespace std;

int max1=0;
void join(int *a, int t, int sum)
{
    int tmp[4] = {0};
    int i, j;
    int s;
    if(t == 1)
    {
        if(max1 < sum) 
            max1 = sum;
        return;
    }
    for(i = 0; i < t - 1; i++)
    {
        for(j = 0; j < i; j++)
            tmp[j] = a[j];
            tmp[j] = a[j]+a[j+1];
            s = sum + tmp[j];
            for (j++; j < t - 1; j++)
                tmp[j] = a[j+1];
            join(tmp, t-1, s);
    }
}

int main() {
    int a[4] = {4,4,5,9};
    int sum = 0;
    join(a, 4, sum);
    cout << "max is " << max1 << endl;
    return 0;
}