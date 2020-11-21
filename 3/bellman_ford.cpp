////#include<iostream>
////#include<list>
//////为了简化代码使用了标准库
////using namespace std;
////
/////**
//// * @param key 代表当前节点编号
//// * @param firstname  代表第一次经过该节点的时间
//// * @param finalname  代表深度搜索完成后的时间
//// * @param color     代表当前节点是否还有未遍历的子节点
//// * @param parent     当前节点的父节点编号
//// */
////typedef struct node {
////    int key=0;
////    int firsttime=0;
////    int finaltime=0;
////    int color=0;
////    int parent=0;
////}Node;
////
/////**
//// * @details *v 是一个邻接表，存储了一个节点与另一个节点相连的信息
//// * @details *arr 维护一个数组，里面记载了所有节点的信息（除了相连的信息
//// * @details time 是一个全局时间变量
//// */
////class Graph{
////public:
////    Graph(int num);
////    void DFS(int a,int b);//深度优先搜索
////    void DFS_Visit(int a,int num);//不断递归，并把经过的点变换状态
////    void addNode(int a,int b);//程序一开始时添加数据，这里用了课件上的数据
////    void showdetails(int num);//展示程序完成时的状态
////private:
////    list<int> *v;
////    Node *arr;//记录详细信息
////    int time=0;
////};
////
////Graph::Graph(int num) {//num代表节点的数量
////    v=new list<int>[num];
////    arr=new Node[num];
////}
////
////void Graph::addNode(int a, int b) {
////    v[a].push_back(b);
////}
////
////void Graph::DFS_Visit(int a,int num) {
////    arr[a].color=1;
////    time++;
////    cout<<"first  "<<a<<endl;
////    arr[a].firsttime=time;
////    for(auto i=v[a].begin();i!=v[a].end();i++){
////        if(arr[*i].color==0){
////            arr[*i].parent=a;
////            DFS_Visit(*i,num);
////        }
////    }
////    arr[a].color=2;
////    cout<<"final  "<<a<<endl;
////    time++;
////    arr[a].finaltime=time;
////
////}
////
////void Graph::DFS(int a,int b) {
////    for(int i=0;i<a;i++){
////        while(arr[i].finaltime==0){
////            DFS_Visit(i,a);
////        }
////
////    }
////}
////
////void Graph::showdetails(int num) {
////    cout<<"firsttime   secondtime"<<endl;
////    for(int i=0;i<num;i++){
////        cout<<arr[i].firsttime<<"             "<<arr[i].finaltime<<endl;
////    }
////}
////
////int main(){
////    Graph *graph=new Graph(6);
////    graph->addNode(0,1);
////    graph->addNode(0,3);
////    graph->addNode(1,2);
////    graph->addNode(2,3);
////    graph->addNode(3,2);
////    graph->addNode(4,2);
////    graph->addNode(4,5);
////    graph->addNode(5,5);
////    cout<<"the order of dfs"<<endl;
////    graph->DFS(6,0);
////    cout<<"the time of each node"<<endl;
////    graph->showdetails(6);
////}
//#include<iostream>
//using namespace std;
//
//class Problem{
//public:
//    void simplecalculate();
//    void exchangemoney();
//};
//
//void Problem::simplecalculate() {
//    cout<<"input"<<endl;
//    float a,b;
//    char c;
//    cin>>a>>c>>b;
//    if(b==0&&c=='/'){
//        cout<<"your input is invalid"<<endl;
//        return;
//    }
//    switch(c){
//        case '+':
//            cout<<a+b<<endl;
//            break;
//        case '-':
//            cout<<a-b<<endl;
//            break;
//        case '*':
//            cout<<a*b<<endl;
//            break;
//        case '/':
//            cout<<a/b<<endl;
//            break;
//        default:
//            cout<<"your input is invalid"<<endl;
//
//    }
//
//}
//
//void Problem::exchangemoney() {
//    int money;
//    int counter=0;
//    cin>>money;
//    if(money%10!=0){
//        cout<<"input is invalid"<<endl;
//        return;
//    }
//    int i,j,k;
//    for (i = 1; i < money/5; i++) {
//        int sum1=0;
//        sum1=sum1+i*5;
//        for (j = 1; j < money/2; j++) {
//            int sum2=0;
//            sum2=sum1+2*j;
//            for (k = 1; k < money; k++) {
//                int sum3=0;
//                sum3=sum2+k;
//                if(sum3==money){
////                    cout<<"the number of 1: "<<k<<endl;
////                    cout<<"the number of 2: "<<j<<endl;
////                    cout<<"the number of 5: "<<i<<endl;
//                    counter++;
//                }
//            }
//        }
//    }
//    cout<<"the total way is : "<<counter<<endl;
//}
//
//int main(){
//    Problem temp;
//    temp.simplecalculate();
//    temp.exchangemoney();
//    return 0;
//}
#define edgenum 10
#define nodenum 5

#include<iostream>
#include<vector>
#include<queue>

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
    int distence=1000;//代表这个节点与源节点之间的距离
    int parent=0;//代表这个节点的上一个节点
    int weight[nodenum]={1000,1000,1000,1000,1000};//代表第i个节点与本节点之间的权重
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

    //vector<edge> we;
};

//输入数据到we和weight中，这两个是一样的，只是为了后面方便运输存了两个
void Graph::inputdata(int i,int j,int k){//输入节点和其他节点相连的权重信息
    //Edge temp(i,j,k);
    //v[i].we.push_back(temp);
    //we.push_back(temp);
    v[i].num=i;
    v[i].weight[j]=k;
}
void Graph::initial(Node *v,int s){
    v[s].distence=0;
    v[s].weight[s]=0;
}

//void Graph::relax(Node m,Node n){
//    if(m.distence+m.weight[n.num]<n.distence){
//        n.distence=m.distence+m.weight[n.num];
//        n.parent=m.num;
//    }
//}

bool Graph::bellman(int s,int number){
    initial(v,s);
    //是把每条边都放松v-1次
    for(int i=0;i<nodenum-1;i++){
        for(int j=0;j<edgenum;j++){
            if(v[edge[j].num1].distence+v[edge[j].num1].weight[edge[j].num2]<v[edge[j].num2].distence){
                v[edge[j].num2].distence=v[edge[j].num1].distence+v[edge[j].num1].weight[edge[j].num2];
                v[edge[j].num2].parent=edge[j].num1;
            }
        }
//        int count=0;
//        while(count!=nodenum){
//            for(int j=0;j<edgenum;j++){
//                if(v[count].weight[j]!=1000)
//                {//下面是relax操作
//                    if(v[count].distence+v[count].weight[j]<v[j].distence){
//                        v[j].distence=v[count].distence+v[count].weight[j];
//                        v[j].parent=count;
//                    }
//                }
//                //relax(v[i],v[j]);
//            }
//            count++;
//        }

    }
     for(int i=0;i<edgenum;i++){
         if(v[edge[i].num2].distence>v[edge[i].num1].distence+edge[i].weight){
             return false;
         }
     }
    return true;
}

void Graph::showdetail(){
    cout<<"parent node  node  weight distence"<<endl;
    for(int i=0;i<nodenum;i++){
        cout<<"      "<<v[i].parent<<"       "<<v[i].num<<"     "<<v[v[i].parent].weight[v[i].num]<<"      "<<v[i].distence<<endl;
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