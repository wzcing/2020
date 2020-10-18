#include<iostream>

using namespace std;

struct sethead{
    int rank=1;
    node* head;
    node *tail= nullptr;
};
struct node{
    int p;
    sethead *parent;
    node *next= nullptr;
};



// node* Make_Set(int i){
//     node *temp;
//     temp->next=nullptr;
//     temp->p=i;
//     temp->parent=temp;
//     temp->rank=0;
//     // temp.p =i;
//     // temp.rank =0;
//     // temp.parent =&temp;
//     // temp.next = nullptr;
//     return temp;
// }

sethead* Make_Set(int i) {
    sethead *temp;
    node *n;
    n->p=i;
    n->parent=temp;
    temp->head=n;
    temp->tail=n;
    return temp;
}

// sethead* Find_Set(node *tem){
//     return tem->parent;
//     // if(tem->parent!=tem){
//     //     tem->parent = Find_Set(tem->parent);
//     // }
//     // return tem->parent;

// }

void Union(sethead *x,sethead *y){
    // node *x=Find_Set(x1);
    // node *y=Find_Set(y1);
    // sethead* x=Find_Set(x1);
    // sethead* y=Find_Set(y1);
    if(x==y) return;
    if(x->rank>y->rank){
        x->tail->next=y->head;
        x->tail=y->tail;
        x->rank+=y->rank;
        y=x;
    }else{
        y->tail->next=x->head;
        y->tail=x->tail;
        y->rank+=x->rank;
        x=y;
    }
//     if(x==y){return;}
//     if(x->rank>y->rank){
//         y->parent=x;
//     }else{
//         x->parent=y;
//         if(x->rank==y->rank){
//             y->rank++;
//         }
//     }
}

void show(sethead *temp){
    node* te=temp->head;
    cout<<temp->rank<<" "<<endl;
    while(te!=nullptr){
        cout<<te->p <<" "<<endl;
        te=te->next;
    }

}
int main(){
    sethead *x1=Make_Set(1);
    sethead *x2=Make_Set(2);
    sethead *x3=Make_Set(3);
    sethead *x4=Make_Set(4);
    sethead *x5=Make_Set(5);
    sethead *x6=Make_Set(6);
    sethead *x7=Make_Set(7);
    Union(x1,x2);
    Union(x3,x4);
    Union(x5,x6);
    
    Union(x2,x4);
    Union(x6,x4);
    Union(x7,x4);
    show(x4);
}

