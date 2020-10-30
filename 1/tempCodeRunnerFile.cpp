node *graph::Make_Set(int data){
    node *temp=new node;
    //Head final;
    temp->data=data;
    temp->next=nullptr;
    temp->parent=temp;
    //final.head=temp;
    //final.tail=temp;
    return temp;
}

node* graph::Find_Set(node a){
    return a.parent;
}

node* graph::Union(node *a, node *b){
    node *x=Find_Set(*a);
    node *y=Find_Set(*b);
    Head *temp1=new Head;
    Head *temp2=new Head;
    if(x==y){return;}
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

        //temp2->head=temp1->head;
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
        //temp2->head=temp1->head;
        y->rank+=x->rank;
        return y;
    }
}