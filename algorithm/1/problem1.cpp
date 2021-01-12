#include<iostream>
#include<time.h>
using namespace std;

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

int main(){
    int a[5];
    a[0] = 2;
    a[1] = 2;
    a[2] = 3;
    a[3] = -2;
    a[4] = 3;
    int n = 5;
    sort(a, n);
    int mid = n / 2;
    int final = 0;
    cout<<"location is "<<a[mid]<<endl;
    for(int i=0; i<n; i++){
        final += abs(a[i] - a[mid]);
    }
    cout<<"full length "<<final<<endl;
}










// #include<iostream>
// #include<vector>

// using namespace std;

// typedef struct point{
//     int x=0;
//     int y=0;
//     //point(int a, int b) : x(a), y(b){};
// } P;
// vector<P> points;

// P arr[5];

// void sort(P *a,int left,int right){ 

// }

// int main(){
//     // points.push_back(P(1, 2));
//     // points.push_back(P(2, 2));
//     // points.push_back(P(1, 3));
//     // points.push_back(P(3, -2));
//     // points.push_back(P(3, 3));

//     // location(points);

//     // arr[0] =  P(1, 2);
//     // arr[1] =  P(2, 2);
//     // arr[2] =  P(1, 3);
//     // arr[3] =  P(3, -2);
//     // arr[4] =  P(3, 3);
//     arr[0].y = 2;
//     arr[1].y = 2;
//     arr[2].y = 3;
//     arr[3].y = -2;
//     arr[4].y = 3;
//     sort(arr, 0, 5);
//     for (int i = 0; i < 5;i++) {
//         cout << arr[i].y << " ";
//     }
// }
// // void location(vector<P> points){
// //     int max, min;
// //     max = points[0].y;
// //     min = points[0].y;
// //     for(int i=0;i<points.size();i++){
// //         if(points[i].y>max){
// //             max = points[i].y;
// //         }
// //         if(points[i].y<min){
// //             min = points[i].y;
// //         }
// //     }
// // }

// // void find(int min,int max,int s){
// //     int ray = min;
// //     int final = 0;
// //     if(ray==max)
// //         return;
// //     for(int i=0;i<points.size();i++){
// //         final = abs(points[i].y - ray);
// //     }
// // }
// // void sort(P *a,int left,int right){
// //     if(left>=right){
// //         return;
// //     }
// //     int mid=(left+right)/2;
// //     sort(a, left, mid);
// //     sort(a, mid + 1, right);
// //     if(a[mid].y > a[right].y){
// //         swap(a[mid],a[right]);
// //     }
// //     sort(a, left, right - 1);
// // }


// // void slowsort(int arr[], int lhs, int rhs)
// // {
// //     // 没什么好排的了就直接投降
// //     if (lhs >= rhs) {
// //         return;
// //     }
// //     // 随便切一刀
// //     // 反正留下最后一个位置就行
// //     auto mid = (lhs + rhs) / 2;
// //     // 让张三帮我去排好前面半段
// //     slowsort(arr, lhs, mid);
// //     // 让李四帮我去排好后面半段
// //     slowsort(arr, mid + 1, rhs);
// //     // 我自己就只需要比一下这两段的最后一个元素     
// //     // 整条数组的最后一个位置就确定了
// //     if (arr[mid] > arr[rhs]) {
// //         std::swap(arr[mid], arr[rhs]);
// //     }
// //     // 好了累死我了
// //     // 还没排好的部分让王五去排
// //     slowsort(arr, lhs, rhs - 1);
// // }
