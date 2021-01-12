#include<iostream>
using namespace std;

int n = 6;
int p[7] = {5, 10, 3, 12, 5, 50, 6};
int m[50][50] = {0};
int s[10][10] = {0};//存储分隔的k值

void find(int n) {
    
    for (int r = 2; r <= n; r++) {//i与j的差值,方便k来分割i和j   ->  i k k+1 j
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

void trace(int i,int j){
    if(i==j){
        cout << "A" << i;
        return;
    }
    else{
        cout << "(";
        trace(i, s[i][j]);
        trace(s[i][j] + 1, j);
        cout << ")";
    }
    
}

int main(){
    find(n);
    cout << "Optimal solution: ";
    cout << m[1][n] << endl;
    trace(1, n);
}






















