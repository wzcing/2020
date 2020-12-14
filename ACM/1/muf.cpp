#include<iostream>

using namespace std;

typedef struct node {
    int data;
    node *parent=nullptr;
    node *next=nullptr;
    int rank=1;//权重
}node;

typedef struct head {
    node *head=nullptr;
    node *tail=nullptr;
}Head;

class graph{
public:
    graph(){};

    node *Make_Set(int data);
    node *Find(node a);
    node *Union(node *a, node *b);
};

node *graph::Make_Set(int data){
    node *temp=new node;
    temp->data=data;
    temp->next=nullptr;
    temp->parent=temp;
    return temp;
}

node* graph::Find(node a){
    return a.parent;
}

node* graph::Union(node *a, node *b){
    node *x=Find(*a);
    node *y=Find(*b);
    Head *temp1=new Head;
    Head *temp2=new Head;
    if(x==y){return a;}
    if(x->rank>y->rank){
        temp1->head=x;
        while(a->next!=nullptr){
            a=a->next;
        }
        temp1->tail=a;
        
        temp2->head=y;
        while(b->next!=nullptr){
            b=b->next;
        }
        temp2->tail=b;

        temp1->tail->next=temp2->head;
        while(y->next!=nullptr){
            y->parent=x;
            y=y->next;
        }
        y->parent=x;

        x->rank+=y->rank;
        return x;
    }else{
        temp1->head=y;
        while(b->next!=nullptr){
            b=b->next;
        }
        temp1->tail=b;
        
        temp2->head=x;
        while(a->next!=nullptr){
            a=a->next;
        }
        temp2->tail=a;
        temp1->tail->next=temp2->head;
        while(x->next!=nullptr){
            x->parent=y;
            x=x->next;
        }
        x->parent=y;
        y->rank+=x->rank;
        return y;
    }
}

//从X节点开始，输出它和它的子节点的shu'j
void show(node *x){
    while(x!=nullptr){
        cout<<x->data<<" ";
        x=x->next;
    }
}

int main(){
    graph x;
    //node *x1=Make_Set(1);
    node *x1=x.Make_Set(1);
    node *x2=x.Make_Set(2);
    node *x3=x.Make_Set(3);
    node *x4=x.Make_Set(4);
    node *x5=x.Make_Set(5);
    x.Union(x1,x2);
    x.Union(x1,x3);
    x.Union(x4,x5);
    x.Union(x5,x3);

    cout<<x.Find(*x5)->data<<endl;
    
    //这里加入集合的顺序是
    //x1,x2->{x1,x2} x2为根节点
    //x3,{x1,x2}->{x1,x2,x3} x2为根节点
    //x5,x4->{x5,x4} x4为根节点
    //{x5,x4},{x1,x2,x3}->{x1,x2,x3,x4,x5} x2为根节点
    //由于UNION算法的关系,最终输出的值顺序为
    //x2,x1,x3,x5,x4
    //为了观看清楚就直接用最后得到的根节点来输出了
    show(x2);
}







