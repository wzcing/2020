#include<iostream>
#include<queue>
int edgenum=0;
int nodenum=0;
using namespace std;

struct point{
    int point1=0;
    int point2=0;
    int weight=0;
    bool operator>(const point& a)const {
        return weight > a.weight;
    }
    bool operator<(const point& a)const {
        return weight < a.weight;
    }
    //point(){}
    point(int a,int b,int c):point1(a),point2(b),weight(c){}
};
point edge[100];
point final[10];
bool v[10];


priority_queue<point, vector<point>,less<point> > p;

void findalledge(){
    for(int i=0;i<edgenum;i++){
        if(v[edge[i].point1]==true||v[edge[i].point2]==true){
            p.push(edge[i]);
        }
    }
}






int a[5]={5,4,3,2,11};

int main(){
    for(int i=0;i<5;i++){
        int point1=0;
        int point2=0;
        int weight=a[i];
        //cin>>point1>>point2>>weight;
        point temp(point1,point2,weight);
        p.push(temp);
    }
    cout<<p.top().point1<<" "<<p.top().point2<<" "<<p.top().weight<<endl;

    for(int i=0;i<nodenum;i++){
        findalledge();
        point temp=p.top();
        while(v[temp.point1]==true&&v[temp.point2]==true&&p.size()>0){
            p.pop();
            temp=p.top();
        }
        final[i]=temp;

    }





}