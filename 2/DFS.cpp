#include<iostream>

using namespace std;

//使用邻接矩阵存储各个节点相连的信息
//相连节点的值为0，不相连节点的值为一无穷大值，设置为1000
//arr[a][b]
//即若节点一、三相连，二、四不相连
//arr[1][3]=0,arr[2][4]=1000

/**
 * @param **arr 存储数据的二维数组 
 * @param a  节点一
 * @param b  节点二
 * 
 * 0 代表未访问过
 * 1 代表访问过，但是还有相连的节点没访问
 * 2 代表访问过，且无相连节点未访问
 */ 
void visit(int **arr,int a,int b) {
    if(arr[a][b]==0){
        arr[a][b]=1;
    }else if(arr[a][b]==1){
        arr[a][b]=2;
    }
}




int main(){

}