// 打印花纹（左）.cpp : 定义控制台应用程序的入口点。
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
		for(j=1;j<=i;j++)
		{
			printf("*  ");
		}
	printf("\n");
	
	}


}

