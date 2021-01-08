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


// void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
// 	int i,j,k;
// 	// i - to mark the index of left aubarray (L)
// 	// j - to mark the index of right sub-raay (R)
// 	// k - to mark the index of merged subarray (A)
// 	i = 0; j = 0; k =0;
// 	while(i<leftCount && j< rightCount) {
// 		if(L[i]  < R[j]) A[k++] = L[i++];
// 		else A[k++] = R[j++];
// 	}
// 	while(i < leftCount) A[k++] = L[i++];
// 	while(j < rightCount) A[k++] = R[j++];
// }
// void MergeSort(int *A,int n) {
// 	int mid,i, *L, *R;
// 	if(n < 2) return; // base condition. If the array has less than two element, do nothing.
// 	mid = n/2;  // find the mid index.
// 	// create left and right subarrays
// 	// mid elements (from index 0 till mid-1) should be part of left sub-array
// 	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
// 	L = new int[mid];
// 	R = new int [n - mid];
// 	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
// 	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray
// 	MergeSort(L,mid);  // sorting the left subarray
// 	MergeSort(R,n-mid);  // sorting the right subarray
// 	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
// 	// the delete operations is very important
// 	delete [] R;
// 	delete [] L;
// }


int main(){
    int a[10] = {0};
	srand(time(NULL));
	for (int i = 0; i < 10;i++){
		int temp = rand() % 100 + 1;
		a[i] = temp;
	}
	cout << "随机生成的数字10个" << endl;
	for (int i = 0; i < 10;i++){
		cout << a[i] << " ";
	}
	cout << endl;
	sort(a, 10);
	cout << "排序结果" << endl;
	for (int i = 0; i < 10;i++){
        cout << a[i] << " ";
    }
}

















