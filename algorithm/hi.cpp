#include<iostream>

using namespace std;

void merge(int *a,int *l,int left,int *r,int right){
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while(i<left&&j<right){
        if(l[i]<=r[j])
            a[k++] = l[i++];
        else
            a[k++] = r[j++];
    }

    while(i<left)
        a[k++] = l[i++];
    while (j<right)
        a[k++] = r[j++];
}








