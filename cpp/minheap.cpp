#include<iostream>
using namespace std;

//没使用泛型，可以更改一下
class minheap{
private:
    int heap[200]={0};//the biggest size 
    int count;//the real size

public:
    void set_cout(int i);
    void exchange(int x, int y);
    void Up(int i);
    void Down(int i,int count);
    void insert(int i);
    void Creatheap();
    int Getmin();
    //int extract_min();
    void decrease_key(int i,int k);
};

void minheap::set_cout(int i){
    count=i;
}
void minheap::exchange(int x,int y){
    int temp=heap[x];
    heap[x]=heap[y];
    heap[y]=temp;
}

void minheap::Up(int i){
    while(i>1&&heap[i/2]>heap[i]){
        exchange(i/2,i);
        i=i/2;
    }
}

void minheap::Down(int i,int count){
    while(2*i<=count){
        int a=2*i;
        if(a<count){
            if(heap[a+1]<heap[a])
                a=a+1;
        }
        if(heap[a]<heap[i]){
            exchange(a,i);
        }else{
            break;
        }
        i=a;
    }
}


void minheap::insert(int i){
    //未考虑超出200的情况
    int a=count+1;
    heap[a]=i;
    Up(a);
}

void minheap::Creatheap(){
    for(int i=1;i<=count;i++){
        int temp=0;
        cin>>temp;
        heap[i]=temp;
        Up(i);
    }
}


int minheap::Getmin(){
    return heap[1];
}

// int minheap::extract_min(){
//     int temp=heap[1];
//     exchange(1,count);

//     Down(1,count--);
//     return temp;
// }

void minheap::decrease_key(int i,int k){
    int temp=0;
    for(int a=1;a<count;a++){
        if(heap[a]==i){
            heap[a]=k;
            temp=a;
        }
    }
    if(temp==0){
        cout<<"no such number"<<endl;
        return;
    }
    Up(temp);
}

int main(){
    minheap test;
    test.set_cout(9);
    test.Creatheap();
    cout<<test.Getmin()<<endl;
    //cout<<test.extract_min()<<endl;
    //
    test.decrease_key(5,1);
    cout<<test.Getmin()<<endl;

    
}