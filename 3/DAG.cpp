//使用了上一次作业的拓扑排序
#define nodenum 6//假设只有6个节点

#include"DFS1.h"
#include<iostream>

using namespace std;

typedef struct DNode
{
    //int num=0;
    //parent为1000代表没有父节点
    //distance为1000代表处于无穷大状态
    //weight[i]为1000代表此节点与i节点不相连
    int parent=1000;
    int distance=1000;
    int weight[6]={1000,1000,1000,1000,1000,1000};//简化情况，考虑每个节点最多与其他节点都相连，即6条边
}DNode;
DNode node[6];

//初始化，设置s节点为起始节点
void initial(int s){
    node[s].distance=0;
}

int main(){
    //节点编号以及相连的节点之间的权重
    node[0].weight[1]=5;
    node[0].weight[2]=3;
    node[1].weight[2]=2;
    node[1].weight[3]=6;
    node[2].weight[3]=7;
    node[2].weight[4]=4;
    node[2].weight[5]=2;
    node[3].weight[4]=-1;
    node[3].weight[5]=1;
    node[4].weight[5]=-2;

    //下面是借用了上一次的拓扑排序算法，获得顺序 这里面的顺序为0 1 2 3 4 5号节点 
    //输入节点以及相连的节点，有方向
    Graph *graph=new Graph(6);
    graph->addNode(0,1);
    graph->addNode(0,2);
    graph->addNode(1,2);
    graph->addNode(1,3);
    graph->addNode(2,3);
    graph->addNode(2,4);
    graph->addNode(2,5);
    graph->addNode(3,4);
    graph->addNode(3,5);
    graph->addNode(4,5);
    //拓扑排序
    graph->topo(6);

//根据PPT，从一号节点开始
    initial(1);
//对于每个节点都进行更新distance
    for(int i=0;i<nodenum;i++){
        //按照拓扑排序的顺序
        //temp为拓扑排序的节点号
        int temp=graph->forDag.front();
        graph->forDag.pop();
        for(int j=0;j<nodenum;j++){
            //由于我设置的结构体关系，需要判断是否相连
            if(node[temp].weight[j]!=1000){
                //进行relax操作
                if(node[temp].distance+node[temp].weight[j]<node[j].distance){
                    node[j].distance=node[temp].distance+node[temp].weight[j];
                    node[j].parent=temp;
                }
            }
        }
    }
//以下为输出数据部分

    cout<<"parent node distance"<<endl;

    for(int i=0;i<nodenum;i++){
        //对数据进行处理，所以1000都换成null
        if(node[i].parent==1000){
            if(node[i].distance==1000){
                cout<<"null"<<"   "<<i<<"      null"<<endl;
            }else{
                cout<<"null"<<"   "<<i<<"      "<<node[i].distance<<endl;
            }
        }else{
            cout<<node[i].parent<<"      "<<i<<"      "<<node[i].distance<<endl;
        }
        
    }

/**结果
parent node distance
null   0      null  
null   1      0     
1      2      2     
1      3      6     
3      4      5     
4      5      3 
*/

}

