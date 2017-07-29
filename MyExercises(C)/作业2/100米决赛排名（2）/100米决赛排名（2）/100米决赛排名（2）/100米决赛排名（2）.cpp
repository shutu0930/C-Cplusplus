// 100米决赛排名（2）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
int main ()
{
	int player[8][2],num[8],i,j,min;
	float temp[8];                                      //temp用来存放选手的成绩

	for(i=0;i<=7;i++)
	{
		player[i][0]=1001+i;
		printf("请输入%d号选手的成绩：",player[i][0]);
		scanf("%f",&temp[i]);
		player[i][1]=temp[i]*100;
	}

	for(i=0;i<=6;i++)
	{
		for(j=i+1;j<=8;j++)
		{
			if(player[i][1]>player[j][1])
			{
				min=player[j][1];
				player[j][1]=player[i][1];
				player[i][1]=min;
			}
		}
	}

	num[0]=1;
	for(i=1,j=1;i<=7;i++,j++)
		{
			if(player[i][1]!=player[i-1][1])
				num[j]=i+1;
			else 
				num[j]=i;
				
				
		}

			for(i=0;i<=7;i++)
				{
					printf("第%d名：\t%d号\t成绩：%1.2f秒\n",num[i],player[i][0],temp[i]);
				}

}