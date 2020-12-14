#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int t[11] = {0};
int a[11] = {2,1,4,6,3,5,7,8,9,10,5};

void merge(int ll, int rr) {
    if (rr - ll <= 1) 
        return;
    int mid = ll + (rr - ll) / 2;
    merge(ll, mid);
    merge(mid, rr);
    int p = ll, q = mid, s = ll;
    while (s < rr) {
        if (p >= mid || (q < rr && a[p] > a[q])) {
            t[s++] = a[q++];
        } else
            t[s++] = a[p++];
    }
    for (int i = ll; i < rr; ++i) 
        a[i] = t[i];
}

int find(int k,int ll,int rr){
    if (ll>rr) return -1;
    int mid = ll + (rr - ll) / 2;

    if(a[mid]==k){
        return mid;
    }else if(a[mid]>k){
        return find(k,ll,mid-1);
    }else{
        return find(k,mid+1,rr);
    }
}

void deletenum(int k){
    int temp = a[k];
    for (int i = 0; i < 11;i++)
    {
        if(a[i]==temp&&i!=k){
            a[i] = 1000;
        }
    }
}
int main( void )
{
    srand(time(NULL));
    
    merge(0,11);


    deletenum(5);
    for (int i = 0; i < 11; i++)
    {
        if(a[i]!=1000){
            printf("%d ", a[i]);
        }else{
            continue;
        }
        
    }
    printf("\n");
    int c=find(5,0,11);
    printf("%d",c);
	return  0;
}
