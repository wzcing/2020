#include<iostream>

using namespace std;

//使用邻接表存储各个节点相连的信息
//假设本次共有6个节点

/**
 * @param key 此节点代表的序号
 * @param firsttime 第一次访问的时间
 * @param finaltime 最后访问的时间
 * @param color 访问状态
 * @param parent 父节点,在输入数据时不输入,由DFS递归中给出
 * @param chil[6] 所有子节点的编号，在输入数据时输入
 */ 
typedef struct node {
    //int key=0;
    int firsttime=0;
    int finaltime=0;
    int color=0;
    int parent=0;
    int chil[6]={1000,1000,1000,1000,1000,1000};

}Graph;

int time=0;//全局时间戳
/**
 * @param *arr 存储数据的二维数组 
 * @param a  节点一
 * @param b  节点二
 * 
 * 0 代表未访问过
 * 1 代表访问过，但是还有相连的节点没访问
 * 2 代表访问过，且无相连节点未访问
 */ 
void DFS_visit(Graph *arr,int a) {
    time++;
    arr[a].firsttime=time;
    arr[a].color=1;
    int num=0;
    while(arr[a].chil[num]!=1000){
        if(arr[arr[a].chil[num]].color==0){
            arr[arr[a].chil[num]].parent=a;
            DFS_visit(arr,arr[a].chil[num]);
            num++;
        }
    }
    arr[a].color=2;
    time++;
    arr[a].finaltime=time;
}

void DFS(Graph *arr){
    for (int i = 0; i < 6; i++)
    {
        if(arr[i].color==0){
            DFS_visit(arr,i);
        }
    }
}



int main(){
    Graph arr[6]={0};
    arr[0].chil[0]=1;
    arr[0].chil[1]=3;
    arr[1].chil[0]=2;
    arr[2].chil[0]=3;
    arr[3].chil[0]=1;
    arr[4].chil[0]=2;
    arr[4].chil[1]=5;
    arr[5].chil[0]=5;
    DFS(arr);
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i].firsttime<<" "<<arr[i].finaltime<<endl;
    }
    
}