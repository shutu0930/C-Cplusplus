// 发牌程序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int flag[52]={0},num[4][13];	//定义标记数组（已初始化都为0）和输出数组
	int i,j,n;
	
	srand((unsigned)time(NULL));		

	for(i=0;i<4;i++)
	{
		printf("%c得到的牌：",65+i);		//A，B，C，D四人拿牌
		for(j=0;j<13;)
		{		
			n=num[i][j]=rand()%52+1;		//随机产生1-52的值
			if(flag[n-1]!=1)				//若标记值不为1，则说明该数不与前面任何数重复
			{	
				flag[n-1]=1;				//使标记值为1
				printf("%3d,",num[i][j]);
				j++;						//j+1使循环进行
				
			}
			
		}	
		printf("\n");
	
	}


}

