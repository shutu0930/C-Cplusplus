// ltrim和rtrim.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#define N 50

void main()
{
	char str[N];
	int i,j,len;
	
	printf("Please input some words:\n");
	gets(str);

	len=(int)strlen(str);
	printf("Before trimmed the length is :%d\n",len);

	for(i=0;i<len;i++)
	{
		if(str[i]!=' ')
		{
			strcpy(str,str+i);
			break;
		}
		
	}

	for(j=(int)strlen(str)-1;j>=0;j--)
	{
		if(str[j]!=' ')
		{
			str[j+1]=0;
			break;
		}
	}
	
	printf("After l trimmed the words are :\n%s\nThe length is :%d\n",str,strlen(str));









}

