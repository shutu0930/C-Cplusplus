// strcmp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#define N 100
void main()
{
	char str1[N];										//定义两个字符串
	char str2[N];

	printf("Please input a string:");                   //输入字符串1、2
	gets(str1);
	printf("Please input another string to compare:");
	gets(str2);


	int i,j,k=0;

	i=strlen(str1);	
	j=strlen(str2);									//分别计算字符串1、2的长度
	

	if(i==j)										//字符串长度相等时比较大小
	{
		while(str1[k]==str2[k])
		{
			k++;
			if(str1[k]=='\0')
				break;

		}

		if(k==i)
			printf("The two strings equal.");			//输出相等
		else
		{
			if(str1[k]>str2[k])
				printf("1st string > 2nd string");
			else
				printf("1st string < 2nd string");
		}
	}

	if(i>j)											//字符串1比字符串2长时比较大小
	{
		while(str1[k]==str2[k])
		{
			k++;
			if(str1[k]=='\0')
				break;
		}

		if(k==j)
			printf("1st string > 2nd string");
		else
		{
			if(str1[k]>str2[k])
				printf("1st string > 2nd string");
			else
				printf("1st string < 2nd string");
		}


	}


	if(i<j)											//字符串2比字符串1长时比较大小
	{
		while(str1[k]==str2[k])
		{
			k++;
			if(str1[k]=='\0')
				break;
		}

		if(k==i)
			printf("1st string < 2nd string");
		else
		{
			if(str1[k]>str2[k])
				printf("1st string > 2nd string");
			else
				printf("1st string < 2nd string");
		}
	}
	
	
	
}

