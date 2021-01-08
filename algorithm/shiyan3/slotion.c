// #include<stdio.h>
// #include<stdlib.h>
// const int maxv = 100;
// const int inf = 100000;
// int n,m,G[100][100];
// int d[100];
// Bool visited[100];
// int prim(){
//     for(int i=0;i<100;i++){
//         d[i] = inf;
//     }
//     d[0] = 0;
//     int ans = 0;
//     for (int i = 0; i < n;i++) {
//         int u=-1,min=inf;
//         for (int j = 0; j < n;j++){
//             if(visited[j]==false&&d[j]<min){
//                 u = j;
//                 min=d[j];
//             }
//         }
//         if(u==-1) return -1;
//         visited[u] = true;
//         ans +=d[u];
//         for(int v = 0; v <= n;v++){
//             if(d[v]==false&&G[u][v]!=inf&&G[u][v]<d[v]){
//                 d[v] = G[u][v];
//             }
//         }
//         return ans;
//     }
// }
// int main(){
//     int u, v, w;
//     for (int i = 0; i < 100;i++){
//         visited[i] == false;
//     }
//     scanf("%d%d", &n, &m);
//     for(int i=0;i<100;i++){
//         for (int j = 0; j < 100;j++){
//             G[i][j] = inf;
//         }
//     }
//     G[0][1] = 5;
//     G[1][0] = 5;
//     G[0][2] = 6;
//     G[2][0] = 6;
//     G[0][3] = 4;
//     G[3][0] = 4;
//     G[1][2] = 1;
//     G[2][1] = 1;
//     G[1][3] = 2;
//     G[3][1] = 2;
//     G[2][3] = 2;
//     G[3][2] = 2;
//     G[2][4] = 5;
//     G[4][2] = 5;
//     G[2][5] = 3;
//     G[5][2] = 3;
//     G[3][5] = 4;
//     G[5][3] = 4;
//     G[4][5] = 4;
//     G[5][4] = 4;
//     for (int i = 0; i < m;i++){
//         scanf("%d%d", &u, &v, &w);
//         G[u][v] = G[v][u] = w;
//     }
//     int ans = prim();
//     //printf("%d\n", ans);
// }
#include<stdio.h>
#include<stdlib.h>

const int maxv = 100;
const int inf = 100000;

int n,m,G[100][100];
int d[100];
int visited[100];

int prim(){
    for(int i=0;i<100;i++){
        d[i] = inf;
    }
    d[0] = 0;
    int ans = 0;
    for (int i = 0; i < n;i++) {
        int u=-1,min=inf;
        for (int j = 0; j < n;j++){
            if(visited[j]==0&&d[j]<min){
                u = j;
                min=d[j];
            }
        }
        if(u==-1) 
            return -1;
        visited[u] = 1;
        switch(u){
            case 0:
                printf("A-");
                break;
            case 1:
                printf("B-");
                break;
            case 2:
                printf("C-");
                break;
            case 3:
                printf("D-");
                break;
            case 4:
                printf("E");
                break;
            case 5:
                printf("F-");
                break;
        }
        ans +=d[u];
        for(int v = 0; v <= n;v++){
            if(visited[v]==0&&G[u][v]!=inf&&G[u][v]<d[v]){
                d[v] = G[u][v];
            }
        }
        
    }
    return ans;
}

int main(){
    int u, v, w;
    for (int i = 0; i < 100;i++){
        visited[i] =0;
        
    }
    for(int i=0;i<100;i++){
        for (int j = 0; j < 100;j++){
            G[i][j] = inf;
        }
    }

    n = 6;
    m = 10;
    
    G[0][1] = 5;
    G[1][0] = 5;
    G[0][2] = 6;
    G[2][0] = 6;
    G[0][3] = 4;
    G[3][0] = 4;
    G[1][2] = 1;
    G[2][1] = 1;
    G[1][3] = 2;
    G[3][1] = 2;
    G[2][3] = 2;
    G[3][2] = 2;
    G[2][4] = 5;
    G[4][2] = 5;
    G[2][5] = 3;
    G[5][2] = 3;
    G[3][5] = 4;
    G[5][3] = 4;
    G[4][5] = 4;
    G[5][4] = 4;

    prim();
    return 0;
}