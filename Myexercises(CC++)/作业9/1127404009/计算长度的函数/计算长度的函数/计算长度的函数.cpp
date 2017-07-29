// 计算长度的函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
void main()
{
	char str[50];
	int count=0;
	
	gets(str);

	while(str[count]!=0)
	{
		count++;
	}

	printf("有%d个有效字符。\n",count);

}

