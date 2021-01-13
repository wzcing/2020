#include<iostream>

using namespace std;

int n = 4;
int m = 2;
int ways = 0;
class Graph{
    private:
        int G[10][10] = {0};
        int colour[10] = {0};
    public:
        void add(int a,int b){
            G[a][b] = 1;
            G[b][a] = 1;
        }
        void output(){
            for (int i = 1; i <= n;i++){
                cout << colour[i] << " ";
            }
            cout << endl;
        }

        int judge(int a){
            for (int i = 1; i <= n;i++){
                if(G[i][a]!=0&&colour[i]==colour[a])
                    return 0;
            }
            return 1;
        }


        void find(int k){
            if(k>n){
                ways++;
                output();
                return;
            }else{
                for (int i = 1; i <= m;i++){
                    colour[k] = i;//此时k的染色
                    if(judge(k)){
                        find(k+1);//深度优先搜索，当上一个节点染色没问题就继续下一个节点的染色
                    }
                    colour[k] = 0;//深度优先搜索返回，重置这个节点的颜色，开始考虑下一个颜色是否可行
                }
            }
        }
};
int main(){
    Graph temp;
    // temp.add(1, 3);
    // temp.add(1, 2);
    // temp.add(1, 4);
    // temp.add(2, 3);
    // temp.add(2, 4);
    // temp.add(2, 5);
    // temp.add(3, 4);
    // temp.add(4, 5);
    // temp.add(1, 2);
    // temp.add(1, 3);
    // temp.add(1, 4);
    // temp.add(2, 3);
    temp.add(1, 2);
    temp.add(1, 3);
    temp.add(2, 4);
    temp.add(3, 4);
    temp.find(1);
    cout << "ways: " << ways;
}




