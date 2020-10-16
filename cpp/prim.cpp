#include<iostream>
using namespace std;

struct point{
    int point1=0;
    int point2=0;
    int weight=0;
    bool operator >(const point& temp)const {
        return this->weight > temp.weight;
    }
};

class minheap{
private:
    point V[9];
    int size=8;

public:
    point Getmin();
    int getsize();
    void setdata(int a, int b, int c,int i);
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
    return size;
}

void minheap::setdata(int a,int b,int c,int i){
    V[i].point1=a;
    V[i].point2=b;
    V[i].weight=c;
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
    while(2*i<=size){
        int a=2*i;
        if(a<size){
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
    exchange(1,size);
    Down(1);
    size--;
}

void minheap::creatheap(){
    for(int i=1;i<=size;i++){
        Up(i);
    }
}

int mian()
{
    minheap mst;
    for(int i=1;i<mst.getsize();i++){
        int point1;
        int point2;
        int weight;
        cin>>point1>>point2>>weight;
        mst.setdata(point1,point2,weight,i);   
    }
    mst.creatheap();
    point final[9];
    int count=1;
    for(int i=1;i<=count;i++){
        
    }


}