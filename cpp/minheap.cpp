#include<iostream>
using namespace std;

//cout refer to the number of the elements in heap
void UpandDown(int cout,int heap[]){
    int i=0,j=i*2;
    //make sure that child node is existing
    while(j<cout){
        //right is bigger than left
        if(j+1<cout&&heap[j+1]>heap[j]){
            j=j+1;
        }
        //if child node is bigger than parent node
        if(heap[j]>heap[i]){
            int temp=heap[i];
            heap[i]=heap[j];
            heap[j]=temp;
            i=j;
            j=i*2;
        }else{
            break;
        }
    }

}

class minheap{
private:
    int heap[20];//the biggest size 
    int cout;//the real size

public:
    void exchange(int x, int y);
    void Up(int i);//move the element up
    void Down(int i);//...down
    void Creatheap(int a[],int length);
    


};

void minheap::exchange(int x,int y){
    int temp=heap[x];
    heap[x]=heap[y];
    heap[y]=temp;
}

void minheap::Up(int i){
    while(i>1&&heap[i/2]<heap[i]){
        exchange(i/2,i);
        i=i/2;
    }
}

void minheap::Down(int i){
    int a=2*i;
    while(a<=cout){
        if(a<cout){
            if(heap[a+1]>heap[a]>)
                a=a+1;
        }
        if(heap[a]>heap[i]){

        }
    }
}
void minheap::Creatheap(int a[],int length){
    
}


int main(){


    return 0;
}