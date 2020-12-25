// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 3 4 0 0 0 4 4 4 4 4 4 4 4 4 4 4 4 4
// 4 5 0 0 0 4 5 5 5 9 9 9 9 9 9 9 9 9
// 7 10 0 0 0 4 5 5 5 10 10 10 14 15 15 15 19 19
// 8 11 0 0 0 4 5 5 5 10 11 11 14 15 16 16 19 21
// 9 13 0 0 0 4 5 5 5 10 11 13 14 15 17 18 19 21
#include<iostream>

using namespace std;

const int maxn = 100;
const int maxv = 1000;

int dp[maxv];
//int w[maxn] = {0,3, 5, 1, 2, 2};
//int c[maxn] = {0,4, 5, 2, 1, 3};
int w[maxn] = {0,3, 4, 7, 8, 9};
int c[maxn] = {0,4, 5, 10, 11, 13};
int main(){
    int n = 5, V = 15;
    //cin >> n >> V;

    cout << "w v ";
    for(int i = 0; i <=V;i++){
        cout << i << " ";
    }

    for (int v = 0; v <= V;v++){
        dp[v] = 0;
    }
    cout << endl;

    for (int i = 0; i < V;i++){
        
        cout << dp[i] << " ";
    }
    cout << endl;


    for (int i = 1;i<=n;i++){
        for (int v = V;v>=w[i];v--){
            dp[v] = max(dp[v], dp[v - w[i]]+ c[i]);
        }
        cout << w[i] << " " << c[i] << " ";
        for (int j = 0; j <= V;j++){
        
            cout << dp[j] << " ";
        }
        cout << endl;
    }
    int max = 0;
    for (int v = 0;v<= V;v++){
        if(dp[v]>max){
            max = dp[v];
        }
    }
    //cout<<max<<endl;
    return 0;

}

