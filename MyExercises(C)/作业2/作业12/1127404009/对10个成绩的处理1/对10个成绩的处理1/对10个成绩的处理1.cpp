// 对10个成绩的处理1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
float max(float num[N])
{
	int j;
	float max;

	max=num[0];
	for(j=1;j<N;j++)
	{
		max=max>num[j]?max:num[j];
	}

	return max;
}


float min(float num[N])
{
	int j;
	float min;

	min=num[0];
	for(j=1;j<N;j++)
	{
		min=min<num[j]?min:num[j];
	}

	return min;


}

float aver(float num[N],float max,float min)
{
	int j;
	float sum=0,aver;
	for(j=0;j<N;j++)
	{
		if(num[j]!=max && num[j]!=min)
			sum+=num[j];
	}
	aver=sum/8;

	return(aver);



}

void main()
{
	float num[N];
	int i;

	srand((unsigned)time(NULL));
	printf("10个评委给选手的评分：\n");
	for(i=0;i<N;i++)
	{
		num[i]=(float)(rand()%10000+1)*0.01;
		printf("%.2f  ",num[i]);
	
	}
	printf("\n最高分为：%.2f  \n最低分为：%.2f  \n去掉最高分和最低分之后的平均分：%.2f  \n",max(num),min(num),aver(num,max(num),min(num)));
	
}