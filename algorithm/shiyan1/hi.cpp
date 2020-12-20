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

void sort(int *a,int n){
    int mid, i, *l, *r;
    if(n<2)
        return;
    mid = n / 2;
    l = new int[mid];
    r = new int[n - mid];
    for (int i = 0; i < mid;i++){
        l[i] = a[i];
    }
    for (int i = mid; i < n;i++){
        r[i - mid] = a[i];
    }
    sort(l, mid);
    sort(r, n - mid);
    merge(a, l, mid, r, n - mid);
    delete[] r;
    delete[] l;
}

int main(){
    int a[10] = {6, 2, 3, 1, 9, 10, 15, 13, 12, 17};
    sort(a, 10);
    for (int i = 0; i < 10;i++)
        cout << a[i] << " ";
}











