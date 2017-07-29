// 删除已输入字符串中的字母.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#define N 50

void main()
{
	char str1[N],str2[N],ch,temp;
	int num[N],i,len,sign;

	printf("Please input some words:\n");
	gets(str1);

	printf("\nPlease input a character to delete:\n");

	getchar(ch);

	len=strlen(str1);
	strcpy(str2,str1);
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{	
			num[i]=i;
			if(str1[i]>str1[j])
			{
				temp=str2[i];
				str2[i]=str2[j];
				str2[j]=temp;


			
			
			}
		
		}
	
	
	}




	


}

