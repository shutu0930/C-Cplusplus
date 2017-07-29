// 将字符串反序存储并输出.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#define N 50
void main()
{
	char str1[N],temp;
	int i,num;

	printf("Plrese input some words:");
	gets(str1);

	num=strlen(str1);

	for(i=0;i<num/2;i++)
	{
		temp=str1[i];
		str1[i]=str1[num-i-1];
		str1[num-i-1]=temp;
	
	}

	puts(str1);


}

