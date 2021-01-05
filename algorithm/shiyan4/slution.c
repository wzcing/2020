#include<stdio.h>
#include<stdlib.h>

int q[9];
int slutions = 0;

int find(int i, int j){
    int temp = 1;
    while(temp<i){
        if(q[temp]==j||abs(temp-i)==abs(q[temp]-j)){
            return 0;
        }
        temp++;
    }
    return 1;
}

void queue(int i){
    int j;
    if(i>8){
        slutions++;
        return;
    }else{
        for (j = 1; j <= 8;j++){
            if(find(i,j)){
                q[i] = j;
                
                queue(i + 1);
            }
        }
    }
}

int main(){
    for (int i = 0; i < 9;i++){
        q[i] = 0;
    }
    queue(1);
    printf("%d",slutions);
    return 0;
}