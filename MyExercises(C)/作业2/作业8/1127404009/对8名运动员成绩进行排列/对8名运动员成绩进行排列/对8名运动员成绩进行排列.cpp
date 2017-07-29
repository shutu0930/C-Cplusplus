// 对8名运动员成绩进行排列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	double grade[8];
	double temp1;
	int num[8];
	int i,j,temp2;
	
	srand((unsigned)time(NULL));
	printf("将8名运动员的100米跑成绩排序，并输出其名次\n编号：");				//将运动员编号1-8
	for(j=0;j<=7;j++)
	{
		num[j]=j+1;
		printf("%-6d",num[j]);
		
	}
	printf("\n成绩：");
	
	for(i=0;i<=7;i++)
	{
		
		grade[i]=0.01*(rand()%700+700);		//随机产生7.00-14.00的运动员成绩
		printf("%-2.2lf ",grade[i]);
		
	}
	printf("\n\n排名：");
	
	for(j=0;j<7;j++)
	{
		for(i=0;i<7-j;i++)
		{
			if(grade[i+1]<grade[i])
			{
				temp1=grade[i];
				grade[i]=grade[i+1];		//冒泡法将成绩排序
				grade[i+1]=temp1;

				temp2=num[i];				//将编号与成绩对应，以便输出
				num[i]=num[i+1];
				num[i+1]=temp2;
			}
		
		}
	}
	

	for(i=0;i<=7;i++)
	{
		printf("%-6d",i+1);				//输出运动员排名
	
	
	}
	printf("\n编号：");
	
	for(j=0;j<=7;j++)
	{
		printf("%-6d",num[j]);			//输出名次所对应的运动员编号
	
	}
	
	printf("\n成绩：");
	for(i=0;i<=7;i++)
	{
		printf("%-2.2lf ",grade[i]);	//输出运动员相应的成绩
	
	}
	printf("\n");


}

