// 筛选排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num[10];							//定义数组
	int i,j,temp;
	srand((unsigned)time(NULL));
	
	printf("Before being sorted the integers:\n");	//随机产生10个要排列的整数
	
	for(i=0;i<=9;i++)
	{
		num[i]=rand();			//10个整数依次赋给数组里的10个数
		printf("%d,",num[i]);
	}
	printf("\n");

	for(j=0;j<=8;j++)
	{
		for(i=0;i<=8-j;i++)					//筛选排序法，按升序排列
		{
			if(num[i+j+1]<num[j])
			{
				temp=num[i+j+1];
				num[i+j+1]=num[j];
				num[j]=temp;
			}
		}
	}
	
	printf("After being sorted the integers:\n");	
	
	for(i=0;i<=9;i++)						//按升序输出各数
	{
		printf("%d,",num[i]);
	}

	printf("\n");

}

