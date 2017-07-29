// shanchu.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
void main()
{
	char str[100];
	
	char letter;

	printf("Please input a string :");
	gets(str);                                                     //输入字符串和要删除的字母
	printf("Pleqse input a letter to delete :");
	letter=getchar();

	int i,j,k;
	for(i=0;i<=99;i++)
	{
		if(str[i]==letter)
			break;
	}

	for(j=0;j<=99;j++)             //计算字符串1的长度
	{
		if(str[j]=='\0')
			break;
	}

	for(k=i;k<=j-1;k++)              //删除输入的字母
	{
		str[k]=str[k+1];
	}


	puts(str);
	
}

