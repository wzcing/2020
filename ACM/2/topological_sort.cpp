#include<iostream>
#include"DFS.h"

using namespace std;

void topo(){

}

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
    graph->topo(6);
    return 0;
}

