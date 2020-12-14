#include<iostream>
#include<queue>
using namespace std;
typedef struct node{
    int a=0;
    int b=0;
    int c=0;
    bool operator > (const node& k)const{
        return c>k.c;
    }
    bool operator < (const node& k)const{
        return c<k.c;
    }
    node(int m,int n,int j):a(m),b(n),c(j){};
}Node;
int main(){
    node m1=node(1,1,1);
    node m2=node(1,1,2);
    node m3=node(1,1,4);
    node m4=node(1,1,39);
    priority_queue<node,vector<node>, less<node> > ki;
    ki.push(m1);
    ki.push(m2);
    ki.push(m3);
    ki.push(m4);
    cout<<ki.top().c;
    // priority_queue<int,vector<int>,less<int> > q;
    // q.push(3);
    // q.push(2);
    // q.push(11);
    // cout<<q.top();
}