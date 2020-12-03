#include<iostream>
#include<queue>

using namespace std;

struct edge{
    int point1=0;
    int point2=0;
    int weight=0;
    bool operator>(const edge& a)const {
        return weight > a.weight;
    }
    edge(int a,int b,int c):point1(a),point2(b),weight(c){};
};
struct  point
{
    int key=1000;
    int parent=0;
    //point(int a,int b):key(a),parent(b){};
};



class graph{
private:
    
    int pointnum=0;
    int edgenum=0;
    int a[100][100];
    priority_queue<edge,vector<edge>,greater<edge> >Edge;
    point p[10];
    point final[10];

public:
    graph(){};
    void setnum(int m,int n){
        pointnum=m;
        edgenum=n;
    };
    void prim();
    void inputdata(int i,int j,int m);//
    void setpoint(int m,int n);//
    void inputalledge(int i,int j,int m);//
    void findalledge(int i);//
};//

void graph::inputdata(int i,int j,int m){//
    edge temp=edge(i,j,m);
    Edge.push(temp);
}

void graph::setpoint(int m,int n){//
    p[m].key=0;
    
    final[m].key=0;
    final[m].key=m;
}

void graph::inputalledge(int i,int j,int m){//
    a[i][j]=m;
}

void graph::findalledge(int k){
    for(int i=0;i<pointnum;i++){
        if(a[k][i]!=1000){
            edge temp=edge(k,i,a[k][i]);
            Edge.push(temp);
        }
    }
}
void graph::prim(){
    for(int i=0;i<pointnum;i++){//初始化整个边点数组
        for(int j=0;j<pointnum;j++){
            a[i][j]=0;
        }
    }

    int willinputnum=0;
    cin>>willinputnum;
    for(int i=0;i<willinputnum;i++){//输入边数据，没有连接点的就是0
        int a=0,b=0,c=0;
        inputalledge(a,b,c);
    }

    int k;
    cin>>k;
    int m,n;
    cin>>m>>n;
    setpoint(k,k);
    setnum(m,n);
    int node=0;
    while(m!=0){
        for(int i=0;i<pointnum;i++){
            findalledge(node);
            if(Edge.top().weight<p[Edge.top().point2].key){
                p[Edge.top().point2].parent=Edge.top().point1;
                Edge.pop();
            }
        
        }
        m--;
    }
    
    for(int i=0;i<pointnum;i++){
        cout<<i<<"  "<<p[i].key<<"  "<<p[i].parent<<endl;
    }


}

int main(){
    graph temp;
    temp.setnum(8,16);
    temp.setpoint(0,0);
    temp.prim();

}










