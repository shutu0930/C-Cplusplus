// 对10个评委打的分数的处理（指针）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#define N 10

void main()
{
	float max_min_aver(float *pnum,float *pmax,float *pmin,int n);

	float num[N],max,min,*p=num,*pmax=&max,*pmin=&min;
	int i;

	printf("Please input 10 scores :\n");					//输入10个评委的打分

	for(i=0;i<10;i++)
	{
		scanf("%f,",p++);
	}
	p=num;

	printf("The max_score is :%.3f\nThe min_score is :%.3f\nThe average_score is :%.3f\n",*pmax,*pmin,max_min_aver(p,pmax,pmin,N-2));

															//利用函数与指针输出最高分最低分和去掉最高最低分得平均值



}
//==================================================================
//本函数用于找出数组中的最大值与最小值并求出去除最大最小值后的平均分
//参数说明：float *p,float *pmax,float *pmin,int n
//==================================================================

float max_min_aver(float *p,float *pmax,float *pmin,int n)
{
	int i;
	float aver,sum=0;
	*pmax=*pmin=*p;					//初始化指针变量

	for(i=0;i<N;i++)
	{
		sum+=*(p+i);				//求和
		if(*pmax<*(p+i))			//利用指针求最大最小值
			*pmax=*(p+i);
		if(*pmin>*(p+i))
			*pmin=*(p+i);
	}

	aver=(sum-*pmax-*pmin)/(N-2);

	return aver;



}