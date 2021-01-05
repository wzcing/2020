#include<iostream>
#include<vector>
using namespace std;

class Graph{
private:
    int points[11][11] = {0};
    int cost[11] = {0};

public:
    void find(int a,int finalnumber);
    void add(int a, int b, int c);
};


void Graph::add(int a,int b,int c){
        points[a][b] = c;
        //points[b][a] = c;
};


void Graph::find(int a,int finalnumber){ 
    if(a==1){
        cout << "the cost is: " << finalnumber << endl;
        return;
    }
    int min = 100;
    for (int i = a; i > 0;i--){
        if(points[a][i]!=0){
            if(points[a][i]<min){
                min=points[a][i];
            }
            
        }
        cout << "the min is: " << min << endl;
        finalnumber += min;
        find(a--,finalnumber);
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

    node.find(10, 0);
    return 0;
}



















