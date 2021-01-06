#include<iostream>
#include<vector>
using namespace std;

class Graph{
private:
    int points[11][11] = {0};
    int cost[11] = {0};
    int path[11] = {0};

public:
    void find(int a,int finalnumber);
    void add(int a, int b, int c);
    Graph(){
        for (int i = 0; i < 11;i++){
            cost[i] = 100;
        }
    }
};


void Graph::add(int a,int b,int c){
        points[a][b] = c;
};


void Graph::find(int a,int finalnumber){
    cost[1] = 0;
    int tempcost = 0;
    for (int i = 2; i < 11;i++){
        for (int j = 1; j < i;j++){
            if(points[j][i]!=0){
                tempcost = cost[j] + points[j][i];
                if(tempcost<cost[i]){
                    cost[i] = tempcost;
                    path[i] = j;
                }
            }
        }
    }

    for (int i = 1; i < 11;i++){
        cout << "V: " << i << " cost: " << cost[i] << endl;
        int k = i;
        cout << "path ";
        while(path[k]){
            k = path[k];
            cout << k << " ";
        }
		cout << endl;
    }

    

}

int main(){

    Graph node;
    node.add(1, 2, 4);
    node.add(1, 3, 2);
    node.add(1, 4, 3);
    node.add(2, 5, 10);
    node.add(2, 6, 9);
    node.add(3, 5, 6);
    node.add(3, 6, 7);
    node.add(3, 7, 10);
    node.add(4, 6, 3);
    node.add(4, 7, 8);
    node.add(5, 8, 4);
    node.add(5, 9, 8);
    node.add(6, 8, 9);
    node.add(6, 9, 6);
    node.add(7, 8, 5);
    node.add(7, 9, 4);
    node.add(8, 10, 8);
    node.add(9, 10, 4);

    node.find(1, 0);
    return 0;
}



















