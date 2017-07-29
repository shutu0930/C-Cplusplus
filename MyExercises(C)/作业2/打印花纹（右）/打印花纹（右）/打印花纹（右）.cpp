// 打印花纹（右）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int i,j,num;

	printf("请输入您要打印的行数：");
	scanf("%d",&num);

	for(i=1;i<=num;i++)
	{
		for(j=num+1-i;j<=num;j++)
		{
			printf("* ");
		}
	printf("\n");
	
	}


}

