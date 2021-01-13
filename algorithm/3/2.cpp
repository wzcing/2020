#include<iostream>
using namespace std;
double w[8] = {1, 11, 21, 23, 33, 43, 45, 55};
double p[8] = {11, 21, 31, 33, 43, 53, 55, 65};
//11  1.9 1.47  1.43  1.3  1.23 1.2 1.18
double bag[111];
//优先选取单位重量价值最大的,由于本题的比值为递减的，所以就省略了这一步,否则排序一下即可
void greedy(double *bag,double *w,double *p){
    //int average[8] = {0};
    // for (int i = 0; i < 8;i++){
    //     average[i] = p[i] / w[i];
    // }

    for (int i = 1; i < 111;i++){
        double tempw = 0.0;
        double tempv = 0.0;
        for (int j = 0; j < 8;j++){
            for (int k = 0; k < w[j];k++){
                tempw++;
                tempv += p[j] / w[j];
                //cout << tempv << endl;
                if(tempw<=i){
                    bag[i] = tempv;
                    //cout << bag[i] << endl;
                }
            }
        }
    }
}
int max(int a,int b){
    return a > b ? a : b;
}
int wq[8] = {1, 11, 21, 23, 33, 43, 45, 55};
int pq[8] = {11, 21, 31, 33, 43, 53, 55, 65};
//11  1.9 1.47  1.43  1.3  1.23 1.2 1.18
int dp[111] = {0};
void dynamic(){
    for (int i = 0; i < 8;i++){
        for (int v = 110; v >= wq[i];v--){
            dp[v] = max(dp[v], dp[v - wq[i]] + pq[i]);
        }
    }
    cout << "use dynamic algorithm: ";
    for (int i = 1; i < 111;i++){
        cout << dp[i] << " ";
    }
}
int main(){
    greedy(bag, w, p);
    cout << "use greddy algorithm: ";
    for (int i = 1; i < 111;i++){
        cout << bag[i] << "   ";
    }
    cout << endl;
    dynamic();
}
