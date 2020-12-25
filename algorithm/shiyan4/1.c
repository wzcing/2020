// #include<stdio.h>
// #include<stdlib.h>

#include <stdio.h>
#include <math.h>
 
#define N_QUEENS 8
 
void Queen();
int Place(int * x, int k);
 
int solutions = 0; //总的解决方案数目
 
int main(void)
{
	Queen();
	printf("Total %d solutions\n", solutions);
 
	return 0;
}
 
void Queen()
{
	int i, k;
	int x[N_QUEENS+1]; //为了表述方便，我们不使用x[0]，因此数组大小多加1
 
	k = 1;
	for (i = 1; i <= N_QUEENS; i++)//初始化
		x[i] = 0;
 
	while (k >= 1)
	{
		x[k]++;//在下一列放置第k个皇后
 
		while (x[k] <= N_QUEENS && !Place(x, k))
			x[k]++;//只要有冲突，就搜索下一列，试图找到第一个不冲突的
 
 
		if (x[k] > N_QUEENS)//这说明第k行所有的都冲突，重置x[k]，回溯，这两行代码才是关键
		{
			x[k] = 0; 						
			k--;
		}
		else if(k < N_QUEENS)//放置下一个皇后
		{
			k++;							
		}
		else // 得到一个解，输出
		{
			for (i = 1; i <= N_QUEENS; i++)
				printf("%d, ", x[i]);
			printf("\n");
 
			solutions++;
		//	return;  //如果只想得到一个解，而不是所有的解，那么需要return 语句
		}
	}
 
}
 
int Place(int * x, int k)//考察皇后k放置在x[k]列是否发生冲突,发生冲突返回0，否则返回1
{
	int i;
 
	for (i = 1; i < k; i++)
		if (x[k] == x[i] || abs(k-i) == abs(x[k]-x[i]))
			return 0;
 
	return 1;
}