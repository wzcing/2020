#include<iostream>
#include<list>
//为了简化代码使用了标准库
using namespace std;
/**
 * @param key 代表当前节点编号
 * @param firstname  代表第一次经过该节点的时间
 * @param finalname  代表深度搜索完成后的时间
 * @param color     代表当前节点是否还有未遍历的子节点
 * @param parent     当前节点的父节点编号
 */
typedef struct node {
    int key=0;
    int firsttime=0;
    int finaltime=0;
    int color=0;
    int parent=0;
}Node;

/**
 * @details *v 是一个邻接表，存储了一个节点与另一个节点相连的信息
 * @details *arr 维护一个数组，里面记载了所有节点的信息（除了相连的信息
 * @details time 是一个全局时间变量
 */
class Graph{
public:
    Graph(int num);
    void DFS(int num);//深度优先搜索
    void DFS_Visit(int a);//不断递归，并把经过的点变换状态
    void addNode(int a,int b);//程序一开始时添加数据，这里用了课件上的数据
    
    void showdetails(int num);//展示程序完成时的状态

    void topo(int num);//拓扑排序和最后结果的展示

private:
    list<int> *v;//存储边的信息
    Node *arr;//记录详细信息
    int time=0;
};

Graph::Graph(int num) {//num代表节点的数量
    v=new list<int>[num];
    arr=new Node[num];
}

void Graph::addNode(int a, int b) {
    v[a].push_back(b);
}

void Graph::DFS_Visit(int a) {
    arr[a].color=1;
    time++;
    cout<<"first  "<<a<<endl;
    arr[a].firsttime=time;
    for(auto i=v[a].begin();i!=v[a].end();i++){
        if(arr[*i].color==0){
            arr[*i].parent=a;
            DFS_Visit(*i);
        }
    }
    arr[a].color=2;
    cout<<"final  "<<a<<endl;
    time++;
    arr[a].finaltime=time;

}

void Graph::DFS(int num) {
    for(int i=0;i<num;i++){
        while(arr[i].finaltime==0){
            DFS_Visit(i);
        }

    }
}

void Graph::showdetails(int num) {
    cout<<"firsttime   secondtime"<<endl;
    for(int i=0;i<num;i++){
        cout<<arr[i].firsttime<<"             "<<arr[i].finaltime<<endl;
    }
}

void Graph::topo(int num){
    cout<<"the order of dfs"<<endl;
    DFS(num);
    cout<<"topological_sort: ";
    int *result=new int[num];
    for(int i=0;i<num;i++){
        result[i]=arr[i].finaltime;
    }

    for(int i=0;i<num;i++){
        int max=0;
        int counter=0;
        for(int j=0;j<num;j++){
            if(result[j]>max){
                max=result[j];
            }
        }
        while(result[counter]!=max){
            counter++;
        }
        result[counter]=0;
        cout<<" "<<counter;

    }

}
/**
 * DFS(G)
 * for each vertexu∈V
 *      u.c←white
 *      u.p←NIL
 * time←0
 * for each vertex u∈V
 *      if u.c=white then
 *          DFS-visit(G,u)

 * DFS-visit(G,u)
 * time←time+1//white vertexuhas just been discovered
 * u.d←time
 * u.c←gray
 * for each edge (u,v)∈E//explore edge (u,v)
 *      if v.c=white then
 *          v.p←u
 *          DFS-visit(G,v)
 * u.c←black//blackenu; it is finished
 * time←time+1
 * u.f←time
 * 
 * O(|V|+|E|).
 * 
 * 
 * 
 * Topological-Sort(G)
 * callDFS(G) to compute finishing times v.f for each vertex v
 * as each vertex is finished, insert it onto the front of a linked list
 * returnthe linked list of vertices
 * 
 * O(|V|+|E|)
 * 
 * 
 */ 