#include<iostream>
using namespace std;

int n = 6;
//int p[7] = {5, 10, 3, 12, 5, 50, 6};
int p[6] = {5, 4, 6, 2, 7};
int m[50][50] = {0};

// int find(int n,int k){
//     for (int i = 1; i <= n;i++){
//         for(int )
//     }
// }

int s[100][100] = {0};
void matrixChain(int n) {
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    for (int r = 2; r <= n; r++) {//i与j的差值
        for (int i = 1; i <= n - r + 1; i++) {
            int j = i + r - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            for (int k = i + 1; k < j; k++) {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (t < m[i][j]) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main(){
    matrixChain(4);
    for (int i = 0; i < 10;i++){
        for (int j = 0; j < 10;j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}






















