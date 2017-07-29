// 输出3X4的矩阵，输出每行的和.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num[3][4];
	int i,j,sum=0;
	
	srand((unsigned)time(NULL));
	printf("Array:\n");				//随机生成一个3*4的矩阵
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=3;j++)
		{
			num[i][j]=rand()%100+1;		//数的范围为1--100
			printf("%5d",num[i][j]);
		
		}
		printf("\n");
	}

	for(i=0;i<=2;i++)
	{
		sum=0;
		for(j=0;j<=3;j++)			//计算每行的和
		{
			sum+=num[i][j];
			
		}
	printf("The total of the %d line is %d\n",i+1,sum);

	
	}













}

