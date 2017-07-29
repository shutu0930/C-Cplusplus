// 求阶乘.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	unsigned int num,prod=1,i=1;
	printf("请输入1-20之间的一个整数：");					//输入
	scanf("%u",&num);

	while(num<1||num>20)
	{
		printf("输入数据错误，请重新输入1~20之间的一个数：");		//输入不合法时重新输入，直到输对为止
		scanf("%u",&num);
	
	}
	
	while(i<=num)											//while语句求其阶乘
	{
		prod=prod*i;
		i++;
	
	}

	printf("该数的阶乘为%u\n",prod);						//输出




}

