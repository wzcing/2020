// 56 12 1 99 1000 234 33 55 99 812

// 1 12 33 55 56 99 99 234 812 1000
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define size 100
// void Quick_Sort(int *a, int l, int r)  //用快速排序的方法对服务时长进行排序
// {
//     if(l<r)
//     {
//         int i=l, j=r;
//         int x=a[l];
//         while(i<j)
//         {
//             while(i<j && a[j]>=x)  j--;
//             if(i<j) a[i++]=a[j];
//             while(i<j && a[i]<x) i++;
//             if(i<j) a[j--]=a[i];
//         }
//         a[i] = x;
//         Quick_Sort(a,l,i-1);
//         Quick_Sort(a,i+1,r);
//     }
// }
// void Greedy(int n, int *t)
// {
//     int wait_time=0,wait_stime=0;  // wait_time: 每个顾客的等待时间，wait_stime: 顾客总的等待时间
//     int i;
//     for(i=1;i<=n;i++)
//     {    
//         wait_time = wait_time+t[i];  //等待时间 = 0 时刻到顾客服务完成时刻的时间间隔
//         wait_stime+=wait_time;      // 总的等待时间更新：加上新的服务顾客的等待时间
//         printf("\nthe %d custoner is %d,wait time:%d",i,t[i],wait_time);
//     }
//     printf("\nall wait time :%d\n", wait_stime);
// }

void merge(int *a,int *l,int left,int *r,int right){
    int i = 0, j = 0, k = 0;
    while(i<left&&j<right){
        if(l[i]<=r[j]){
            a[k++] = l[i++];
        }else{
            a[k++] = r[j++];
        }
    }
	while(i<left){
		a[k++] = l[i++];
    }
    while(j<right){
        a[k++] = r[j++];
    }
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
        r[i-mid] = a[i];
    }

    sort(l, mid);
    sort(r, n - mid);
    merge(a, l, mid, r, n - mid);
}

int main()
{
    int waittime = 0, averagetime = 0;
    // int i,n=10;
    int t[10] = {56,12,1,99,1000,234,33,55,99,812};
    // int aaa[10] = {1, 10,12, 33, 55, 99, 99, 234, 812, 1000};
    // int waitd = 0;
    // int final = 0;
    // for (int i = 0; i < 10;i++) {
    //     int temp = aaa[i];
    //     waitd +=temp;
    //     final +=waitd;
    //     cout << "wait time :" << waitd << endl;
    // }
    // cout<<"final: "<<final<<endl;

    sort(t, 10);
    // for(int i=0; i < 10;i++){
    //     cout<<t[i]<<endl;
    // }

    for (int i = 0; i < 10; i++){
        int temp = t[i];
        cout << "the " << i + 1 << " customer serve time is: " << temp << " wait time is: " << waittime << endl;
        waittime += temp;
        averagetime+=waittime;
    }
    cout << "average wait time is: " << averagetime / 10 << endl;

    // int l, r;
    // l=1;  //快速排序的左边界
    // r=n; //快速排序的右边界
    // Quick_Sort(t,l,r);
    // Greedy(n,t); 

}
