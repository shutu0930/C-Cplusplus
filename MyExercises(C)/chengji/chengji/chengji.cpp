// chengji.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int score[8][2],temp[8][2];
	int i,j;
	int temp;

	for(i=0;i<=7;i++)
	{
		printf("第%d位运动员号码为：",i+1);
		scanf("%d",score[i][0]);
		printf("第%d位运动员成绩为：",i+1);
		scanf("%d",score[i][1]);
		strcpy(temp,score);
	}

	for(i=0;i<=7;i++)
	{
		if(score[i][1]>score[i+1][1])
		{
			score[i+1][1]=score[i][1];
		}
	}
	
	return 0;
}

