#define edgenum 10  // 这里假定只有10条边和5个节点
#define nodenum 5 //

#include<iostream>

using namespace std;

typedef struct Edge
{
    int num1=0;
    int num2=0;
    int weight=0;
}Edge;
Edge edge[edgenum];//存储节点与其他节点相连的权重信息

typedef struct node
{
    int num=0;//代表这个节点的序号
    int distance=1000;//代表这个节点与源节点之间的距离
    int parent=0;//代表这个节点的上一个节点
    int weight[nodenum]={1000,1000,1000,1000,1000};//代表第i个节点与本节点之间的权重,这里现在只有5个节点
}Node;

class Graph{
public:
    Graph(){};
    void inputdata(int i,int j,int k);//代表第i节点与第j节点之间的权重为k
    void initial(Node *v,int s);//表示在一个节点数组里面第S个节点为开始节点
    bool bellman(int s,int number);//s代表根节点，number代表节点的数量
    void showdetail();
private:
    Node v[nodenum];
};

void Graph::inputdata(int i,int j,int k){//输入节点和其他节点相连的权重信息
    v[i].num=i;
    v[i].weight[j]=k;
}

void Graph::initial(Node *v,int s){
    v[s].distance=0;
    v[s].weight[s]=0;
}

bool Graph::bellman(int s,int number){
    initial(v,s);
    //是把每条边都放松v-1次
    for(int i=0;i<nodenum-1;i++){
        for(int j=0;j<edgenum;j++){
            //进行relax操作
            if(v[edge[j].num1].distance+v[edge[j].num1].weight[edge[j].num2]<v[edge[j].num2].distance){
                v[edge[j].num2].distance=v[edge[j].num1].distance+v[edge[j].num1].weight[edge[j].num2];
                v[edge[j].num2].parent=edge[j].num1;
            }
        }
        
    }
    //判断有无负权回路
    for(int i=0;i<edgenum;i++){
        if(v[edge[i].num2].distance>v[edge[i].num1].distance+edge[i].weight){
            return false;
        }
    }
    return true;
}

void Graph::showdetail(){
    cout<<"parent node  node  weight distance"<<endl;
    for(int i=0;i<nodenum;i++){
        cout<<"      "<<v[i].parent<<"       "<<v[i].num<<"     "<<v[v[i].parent].weight[v[i].num]<<"      "<<v[i].distance<<endl;
    }
}



int main(){
    Graph ford;
    ford.inputdata(0,1,6);
    ford.inputdata(0,3,7);
    ford.inputdata(1,2,5);
    ford.inputdata(2,1,-2);
    ford.inputdata(1,3,8);
    ford.inputdata(1,4,-4);
    ford.inputdata(3,2,-3);
    ford.inputdata(3,4,9);
    ford.inputdata(4,0,2);
    ford.inputdata(4,2,7);
    edge[0]={0,1,6};
    edge[1]={0,3,7};
    edge[2]={1,2,5};
    edge[3]={2,1,-2};
    edge[4]={1,3,8};
    edge[5]={1,4,-4};
    edge[6]={3,2,-3};
    edge[7]={3,4,9};
    edge[8]={4,0,2};
    edge[9]={4,2,7};
    bool temp=ford.bellman(0,nodenum);
    if(temp==true){
        ford.showdetail();
    }else{
        cout<<"存在负回路"<<endl;
    }
}