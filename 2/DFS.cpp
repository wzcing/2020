#include<iostream>

#include"DFS.h"

using namespace std;

int main(){
    Graph *graph=new Graph(6);
    graph->addNode(0,1);
    graph->addNode(0,3);
    graph->addNode(1,2);
    graph->addNode(2,3);
    graph->addNode(3,1);
    graph->addNode(4,2);
    graph->addNode(4,5);
    graph->addNode(5,5);
    cout<<"the order of dfs"<<endl;
    graph->DFS(6);
    cout<<"the time of each node"<<endl;
    graph->showdetails(6);
}
