// 8名运动员成绩排序（处理并列情况）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
void main()
{
	double grade[8][2];
	double temp1,temp2;
	int num[8];
	int i,j,temp;
	
	//srand((unsigned)time(NULL));
	printf("将8名运动员的100米跑成绩排序，并输出其名次\n（用空格隔开）\n编号：");				//将运动员编号输入
	for(j=0;j<=7;j++)
	{
		grade[j][0]=(j+1)*1.0;
		printf("%.0lf    ",grade[j][0]);
		//scanf("%d ",&temp);
		//grade[j][0]=temp*1.0;
		
	}
	printf("\n成绩：");
	
	for(i=0;i<=7;i++)
	{
		
		//grade[i][1]=0.01*(rand()%700+700);		
		//printf("%-2.2lf ",grade[i][1]);
		scanf("%lf ",&grade[i][1]);
		
	}
	
	printf("\n\n排名：");
	
	for(j=0;j<7;j++)
	{
		for(i=j+1;i<8;i++)
		{
			if(grade[j][1]>grade[i][1])
			{
				temp1=grade[i][1];
				grade[i][1]=grade[j][1];		//将成绩排序
				grade[j][1]=temp1;

				temp2=grade[i][0];				//将编号与成绩对应，以便输出
				grade[i][0]=grade[j][0];
				grade[j][0]=temp2;
			}
		
		}
	}
	

		num[0]=1;
		for(i=1,j=1;j<8;i++,j++)				//处理并列情况
		{
			if(grade[j][1]!=grade[j-1][1])
			num[j]=i+1;
			else 
			num[j]=num[j-1];
				
				
		}

	
		
		for(i=0;i<8;i++)
		{
			printf("%-6d",num[i]);	
		}										//输出运动员排名
	
	
	printf("\n编号：");
	
	for(j=0;j<=7;j++)
	{
		printf("%.0lf     ",grade[j][0]);			//输出名次所对应的运动员编号
	
	}
	
	printf("\n成绩：");
	
	for(i=0;i<=7;i++)
	{
		printf("%-2.2lf ",grade[i][1]);	//输出运动员相应的成绩
	
	}
	printf("\n");


}



