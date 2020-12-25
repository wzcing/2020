#include<iostream>
#include<algorithm>
using namespace std;
int factorial(int n){
    if(n<=1)
        return 1;
    return n*factorial(n-1);
}
void findrank(int* a,int n){
    // i++;
    // if(n==1)
    //     return 1;
    // int num = a[i] - 1;
    // for(int )
    // for (int k = i+1; k < n;k++){
    //     a[k] = a[k] - 1;
    // }
    // int temp = factorial(n - 1);
    // //cout << temp << endl;
    // return num*temp+findrank(a,n-1);

    int temp = 0;
    for(int i=0; i < n; i++){
        int k = a[i], count = 0;
        for (int j = i;j<n;j++){
            if(k>a[j])
                count++;
        }
        temp += count * factorial(n - i - 1);
    }
    cout <<"the serial number is "<< temp << endl;
}


/*********************
 * a[0]=2   n=8  temp=7!  (2-1)*7!
 * a[1]=6  n=7  temp=6!   (5-1)*6!
 * 
 */ 
int main(){
    int a[8] = {2,6,4,5,8,1,7,3};
    findrank(a, 8);
    next_permutation(a, a + 8);
    cout << "the next one is ";
    for(int i=0; i < 8; i++){
        cout << a[i];
    }
}
