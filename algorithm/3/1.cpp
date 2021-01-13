#include<iostream>
using namespace std;
int a[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int findtimes[11] = {0};
int find(int *a,int l,int r,int value,int findtime){
    if(l>r){
        return -1;
    }
    int mid = (l + r) / 2;
    findtime++;
    if(value>a[mid]){
        l = mid + 1;
        find(a, l, r, value,findtime);
    }else if(value<a[mid]){
        r = mid - 1;
        find(a, l, r, value,findtime);
    }else{
        return findtime;
    }
    //return 0;
}
int main(){

    for (int i = 0; i < 11;i++){
        findtimes[i] = find(a, 0, 10, a[i], findtimes[i]);
    }
    cout << "each number's search times: ";
    for (int i = 0; i < 11;i++){
        cout << findtimes[i] << " ";
    }
    cout << endl;
    int average = 0;
    for (int i = 0; i < 11;i++){
        average += findtimes[i];
    }
    cout << average << endl;
    cout << "average search times: " << average / 11;
}



























