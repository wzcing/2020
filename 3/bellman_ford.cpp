#define mal(x,y) (x*y)

#include<iostream>

using namespace std;
int main(){
    int i=3;
    int a;
    char **b[5][6];
    a=mal(i++,sizeof(b)+5);
    printf("%d",a);
    return 0;


}