// shanchu.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
void main()
{
	char str[100];
	
	char letter;

	printf("Please input a string :");
	gets(str);                                                     //�����ַ�����Ҫɾ������ĸ
	printf("Pleqse input a letter to delete :");
	letter=getchar();

	int i,j,k;
	for(i=0;i<=99;i++)
	{
		if(str[i]==letter)
			break;
	}

	for(j=0;j<=99;j++)             //�����ַ���1�ĳ���
	{
		if(str[j]=='\0')
			break;
	}

	for(k=i;k<=j-1;k++)              //ɾ���������ĸ
	{
		str[k]=str[k+1];
	}


	puts(str);
	
}

