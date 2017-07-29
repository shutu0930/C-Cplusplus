// 产生30个（1-50）的随机数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num[30];
	int i=0;

	srand((unsigned)time(NULL));
	num[i]=rand()%50+1;
	do
	{
		i+=1;
		num[i]=rand()%50+1;
		printf("%d,",num[i]);
	
	}while(num[i]!=num[i-1]);










}

