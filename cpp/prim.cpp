#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct point{
    int point1=0;
    int point2=0;
    int weight=0;
    bool operator >(const point& temp)const {
        return this->weight > temp.weight;
    }
};

//在这个类中只处理输入进来的边
class minheap{
private:
    point V[60]={0};
    int size=1;//由于没用第零个位置，所以真实大小要减一
    int realsize=size-1;

public:
    point Getmin();
    int getsize();
    void clean();
    void setdata(point p);//插入新的边
    void Up(int i);
    void Down(int i);
    void exchange(int i,int j);
    void extract_min();
    void creatheap();
    minheap(){};
    ~minheap(){};
};

point minheap::Getmin(){
    return V[1];
}

int minheap::getsize(){
    return realsize;
}

void minheap::clean(){
    V[60]={0};
}
void minheap::setdata(point p){
    V[size].point1=p.point1;
    V[size].point2=p.point2;
    V[size].weight=p.weight;
    Up(size);
    size++;
}
void minheap::exchange(int i,int j){
    point temp=V[i];
        V[i]=V[j];
        V[j]=temp;
}

void minheap::Up(int i){
    while(i>1&&V[i/2]>V[i]){
        exchange(i/2,i);
        i=i/2;
    }
}

void minheap::Down(int i){
    while(2*i<=realsize){
        int a=2*i;
        if(a<realsize){
            if(V[a]>V[a+1])
                a=a+1;
        }
        if(V[i]>V[a]){
            exchange(a,i);
        }else{
            break;
        }
        i=a;
    }
}
void minheap::extract_min(){
    exchange(1,realsize);
    size--;
    Down(1);
    
}

void minheap::creatheap(){
    for(int i=1;i<=realsize;i++){
        Up(i);
    }
}

// point find_point(int po,point p[],int size){
//     int i=0;
//     while(i<=size){
//         if(p[i].point1==po||p[i].point2==po){
//             return p[i];
//         }
//         i++;
//     }
// }

minheap mst;
bool V[9]={false};//点
point Edges[60];//所有的边
point ve[8];//按顺序存下最小生成树的边
int count1=0;

void findallpoint(int po,point p[], int size){
    mst.clean();
    int i=1;
    while(i<=size){
        if(p[i].point1==po||p[i].point2==po){
            mst.setdata(p[i]);
        }
        i++;
    }
}
bool judeg(bool V[]){
    for(int i=1;i<9;i++){
        if(V[i]==false){
            return false;
        }
    }
    return true;
}

int getnewpoint(){
    
    //if(mst.Getmin().point1==i&&V[mst.Getmin().point2]==false){
    if(V[mst.Getmin().point2]==false&&V[mst.Getmin().point1]==true){
        ve[count1]=mst.Getmin();
        V[mst.Getmin().point2]==true;
        count1++;
        return mst.Getmin().point2;
    }else if(V[mst.Getmin().point1]==false&&V[mst.Getmin().point2]==true){
        ve[count1]=mst.Getmin();
        V[mst.Getmin().point1]==true;
        count1++;
        return mst.Getmin().point1;
    }else{
        if(mst.getsize()!=0){
            mst.extract_min();
            getnewpoint();
        }else{
            return 0;
        }
    }
    return 0;
}

int main()
{
    
//为了简化直接设置16条边,8个点
    for(int i=1;i<17;i++){
        int point1;
        int point2;
        int weight;
        cin>>point1>>point2>>weight;
        Edges[i].point1=point1; 
        Edges[i].point2=point2;
        Edges[i].weight=weight;
        // mst.setdata(point1,point2,weight);   
    }
//首先引入第一个点 标号为 1
    V[1]=true;
    findallpoint(1,Edges,16);
    mst.creatheap();//生成最小堆
    
    while(judeg(V)){
        int temp=getnewpoint();//从最小堆里面得到新的一个点，并设置V[i]=true
        for(int i=1;i<9;i++){//进行遍历，把新的到的点和它相连的边放入新的堆中
            if(V[i]==true){
                findallpoint(i,Edges,16);
            }
        }
    }
    for(int i=0;i<9;i++){
        cout<<ve[i].point1<<" "<<ve[i].point2<<" "<<ve[i].weight<<endl;
    }
    priority_queue<int> q;
    
    return 0;
}