#include<iostream>
#include<queue>

using namespace std;

struct point{
    int point1=0;
    int point2=0;
    int weight=0;
    bool operator>(const point& a)const {
        return weight > a.weight;
    }
    //point(){}
    point(int a,int b,int c):point1(a),point2(b),weight(c){}
};

priority_queue<point, vector<point>,greater<point> > p;
int a[5]={5,4,3,2,1};

int main(){
    for(int i=0;i<5;i++){
        int point1=0;
        int point2=0;
        int weight=0;
        cin>>point1>>point2>>weight;
        point temp(point1,point2,weight);
        p.push(temp);
    }
    cout<<p.top().point1<<" "<<p.top().point2<<" "<<p.top().weight<<endl;
}