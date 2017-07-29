// 在10个随机数中找最小数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num[10];						//定义整型数组
	int i,j=1,sum,min;
	float aver;
	
	srand((unsigned)time(NULL));
	for(i=0;i<=9;i++)
	{
		num[i]=rand();
		printf("%d\n",num[i]);			//随机产生10个数并将它们分别赋给数组的各个元素
	
	}
	min=num[0];
	sum=num[0];
	for(i=1;i<=9;i++)					//求出最小值
	{
		if(num[i]<min)
		{
			j=i+1;						//j的值为最小值的序数
			min=num[i];
		}
	
	sum+=num[i];						//求10个数的和
	
	
	}

	aver=(float)sum/10;					//计算10个数的平均值
	
	printf("最小值为%d，是第%d个数，这10个数的平均值为%.1f\n",min,j,aver);


	






}

