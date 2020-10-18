#include<iostream>
#include<queue>

using namespace std;

//为了简化代码故使用了STL里面的优先队列
//所用到的功能均可以由前两份作业代码改动一下得到



struct point{
    int point1=0;
    int point2=0;
    int weight=0;
    bool operator>(const point& a)const {
        return weight > a.weight;
    }
    //point(){}
    //point(int a,int b,int c):point1(a),point2(b),weight(c){}
};

priority_queue<point,vector<point>,greater<point> > primqueue;

point Edges[60];//存储所有的边
bool V[8]={0};//确定点是否已经全部遍历
point final[8];



void findalledges(int size,int edge){
    for(int i=0;i<edge;i++){//遍历，想要找到和一个点相连的所有边
        for(int j=0;j<size;j++){
            if(V[j]==true){//遍历所有在集合中的点
                if(Edges[i].point1==j&&V[Edges[i].point2]==false||V[Edges[i].point1]==false&&Edges[i].point2==j){//如果一个点是j一个点不在集合中的话那就加进来
                    primqueue.push(Edges[i]);
                    //V[Edges[i].point2]=true;//把点设置为已加入集合
                    //V[Edges[i].point1]=true;//为了方便就没判断了
                }
            }
        }
        
    }
}


void test(){
    int num=0;
    for(int j=0;j<8;j++){
        if(V[j]==false){
            num++;
        }
    }
    if(num==0){
        for(int j=0;j<8;j++){
            cout<<final[j].point1<<" "<<final[j].point2<<" "<<final[j].weight<<endl;
        }
        return;
    }
}


int main() {
    //输入数据
    int size=0;
    int edge=0;
    int count=0;
    cin>>size>>edge;
    for(int i=0;i<edge;i++){
        int point1=0;
        int point2=0;
        int weight=0;
        cin>>point1>>point2>>weight;
        //Edges[i](point1,point2,weight);
        Edges[i].point1=point1;
        Edges[i].point2=point2;
        Edges[i].weight=weight;
    }

    
    V[0]=true;//首先加入一个0点
    for(int i=0;i<8;i++){
        
        findalledges(size,edge);
        point temp=primqueue.top();
        while(V[temp.point1]==true&&V[temp.point2]==true&&primqueue.size()>0){
            primqueue.pop();
            temp=primqueue.top();
        }
        V[temp.point1]=true;
        V[temp.point2]=true;
        primqueue.pop();
        final[count]=temp;
        count++;
    }
    for(int i=0;i<count-1;i++){
        cout<<final[i].point1<<" "<<final[i].point2<<" "<<final[i].weight<<endl;
    }
}
//以下为输入数据
//8个顶点，16条边
// 8
// 16
// 4
// 5
// 35  
// 4
// 7
// 37
// 5
// 7
// 28
// 0
// 7
// 16
// 1
// 5
// 32
// 0
// 4
// 38
// 2
// 3
// 17
// 1
// 7
// 19
// 0
// 2
// 26
// 1
// 2
// 36
// 1
// 3
// 29
// 2
// 7
// 34
// 6
// 2
// 40
// 3
// 6
// 52
// 6
// 0
// 58
// 6
// 4
// 93