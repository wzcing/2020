#include<iostream>
#include<random>
#include<stdlib.h>
#include<time.h>
using namespace std;

//没使用泛型
//并且设置了最大空间
class minheap{
private:
//heap[0]舍弃不用
    int heap[201]={0};//最大空间，并存储权重
    int count;//真实大小

public:
    void set_count(int i);
    void exchange(int x, int y);//交换序号为X,Y的两个数组元素
    void Up(int i);//不断把一个节点和它的父节点相比较，使得小的那一个成为父节点
    void Down(int i,int count);//大的那一个成为子节点
    void insert(int i);//总是插入到数组最后
    void Creatheap(int a[]);
    void decrease_key(int i,int k);
    void show();
    int Getmin();//获得第一个，即heap[1]
    int extract_min();//去掉第一个，再修复
    minheap(){};
    ~minheap(){};

};

void minheap::set_count(int i){
    count=i;
}
void minheap::exchange(int x,int y){
    int temp=heap[x];
    heap[x]=heap[y];
    heap[y]=temp;
}

void minheap::show(){
    for(int i=1;i<=count;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
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

void minheap::Creatheap(int a[]){
    for(int i=1;i<=count;i++){
        heap[i]=a[i];
        Up(i);
    }
}


int minheap::Getmin(){
    return heap[1];
}

int minheap::extract_min(){
    //另一种思路是把数组内除第一位外都朝前挪一位，不过第一位的数据就没了
    int temp=heap[1];
    exchange(1,count);
    heap[count]=100000;
    int a=count--;
    Down(1,a);
    count--;
    return temp;
}
/**
 * @param i 原本的值
 * @param k 要替换的值
 */ 
void minheap::decrease_key(int i,int k){
    int temp=0;
    for(int a=1;a<=count;a++){
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
    int a[10]={0,34,15,56,32,67,22,58,27,99};
    //由于是随机生成的，所以可能会有两个一样的数字同时出现的状况
    //比如最小数字有两个
    //这时候结果可能不是那么直观
    test.set_count(9);//设置9个数字，最大为200个，也可以更改
    test.Creatheap(a);

    test.show();
    cout<<"================================================================"<<endl;
    cout<<"after getmin "<<endl;
    cout<<test.Getmin()<<endl;
    cout<<"================================================================"<<endl;
    cout<<test.extract_min()<<endl;
    cout<<"after extract_min "<<endl;
    cout<<test.Getmin()<<endl;
    cout<<"================================================================"<<endl;
    test.decrease_key(99,5);
    cout<<"after decrease_key "<<endl;
    cout<<test.Getmin()<<endl;
    cout<<"================================================================"<<endl;
    test.insert(2);
    cout<<"after insert 2"<<endl;
    cout<<test.Getmin()<<endl;
    
}
//最终结果

// 15 27 22 32 67 56 58 34 99 
// ================================================================
// after getmin 
// 15
// ================================================================
// 15
// after extract_min 
// 22
// ================================================================
// after decrease_key 
// 5
// ================================================================
// after insert 2
// 2